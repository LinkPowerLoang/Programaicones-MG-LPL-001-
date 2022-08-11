#include "AdafruitIO_WiFi.h"
#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sensor = Adafruit_SHT31();

#include <Adafruit_NeoPixel.h>

#define PIXEL_COUNT 4
#define PIXEL_PIN_1 15
#define PIXEL_PIN_2 13

Adafruit_NeoPixel neopixel1(PIXEL_COUNT, PIXEL_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neopixel2(PIXEL_COUNT, PIXEL_PIN_2, NEO_GRB + NEO_KHZ800);

#include <TB6612_ESP32.h>

//MOTOR2
#define BIN1 25
#define BIN2 26
#define PWMB 14

const int offsetB = -1;

Motor motor = Motor(BIN1, BIN2, PWMB, offsetB, 0, 5000, 8, 2);

#include <EasyBuzzer.h>
int BUZZER_PIN = 27;

int sensorPir = 17;
int datoPir;

int rojo = 4; 
int led = 16;

int fotodiodo = 2;


#define IO_USERNAME  "LinkPowerLoang"
#define IO_KEY       "aio_JmPf03aQW9nzpDnUysnCv9oK2vtH"

#define WIFI_SSID       "Familia_G-Ch"
#define WIFI_PASS       "FamiliK.13"

unsigned long timer1 = 0;
unsigned long timer2 = 0;

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *intensidad_luces = io.feed("intensidad_luces");
AdafruitIO_Feed *luces = io.feed("luces");
AdafruitIO_Feed *hexcolor = io.feed("hexcolor");

AdafruitIO_Feed *tempIO = io.feed("Temp");
AdafruitIO_Feed *humeIO = io.feed("hume");


void setup() {
   Serial.begin(115200);
   Wire.begin(21,22);
  if(sensor.begin(0x44)){
    Serial.println("Sensor encontrado");
  }else{
    Serial.println("Sensor NO encontrado");
    while(1){
      delay(10);
    }
  }
  pinMode(rojo, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(fotodiodo, INPUT_PULLUP);
  EasyBuzzer.setPin(BUZZER_PIN);

   Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.println(io.statusText());
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  intensidad_luces ->onMessage(funcion_intensidad_luces);
  luces ->onMessage(funcion_luces);
  hexcolor ->onMessage(funcion_hexcolor);     

}

void loop() {
 io.run();
  
 float Temp = sensor.readTemperature();
 float hume = sensor.readHumidity();
 int velocidad = 80;
  //isnan -> is not a number?
if (millis() -timer1>=6000){
 if(!isnan(Temp)){
   Serial.print("Temperatura *C = ");
   Serial.println(Temp);
    tempIO-> save(Temp);
    timer1 = millis ();
                 if (Temp<30)
    {
      brake(motor, motor);
    }
    
    else
    {
      forward(motor, motor, velocidad);
    }
}
  }
    
  else{
    Serial.println("Error al obtener temperatura");
}

  //! isnan -> is not not a number? -> is a number?
  if (millis() -timer2>=6000){
  if(!isnan(hume)){
    Serial.print("Humedad % = ");
    Serial.println(hume);
    humeIO->save(hume);
    timer2 = millis();
  }
  }
  else
  {
    Serial.println("Error al obtener humedad");
  }
  
  datoPir = digitalRead(sensorPir);
 if (datoPir == HIGH)
 {
  Serial.println("Alerta se dectecto movimiento");
  digitalWrite(rojo, HIGH);
  EasyBuzzer.beep(1000);
 }
 else
 {
  Serial.println("No se encontor movimiento ");
  digitalWrite(rojo, LOW);
  EasyBuzzer.stopBeep();
 }
 delay(100);

//fotoresistecia si no hay luz se prende
 if (digitalRead(fotodiodo)== LOW) 
  {
  digitalWrite(led, HIGH);
     }
  else
    {
    digitalWrite(led, LOW);
  }
  
}


int flag_luces = 0;
int r = 20;
int g = 20;
int b = 20;

void funcion_luces(AdafruitIO_Data *data)
{
  Serial.println("Funcion de luces");
  if(flag_luces)
  {
    neopixel1.clear();
    neopixel2.clear();
    neopixel1.show();
    neopixel2.show();
    flag_luces = 0;
  }

  else
  {
     for(int i = 0; i < PIXEL_COUNT; i++){
    neopixel1.setPixelColor(i, neopixel1.Color(r,g,b));
    neopixel2.setPixelColor(i, neopixel2.Color(r,g,b));
     }
    neopixel1.show();
    neopixel2.show();
    flag_luces = 1;
  }
}

void funcion_hexcolor(AdafruitIO_Data *data)
{
  Serial.println("Cambio de color de luces");
  String hexValue = data->toString();
  hexValue = hexValue.substring(2);
  Serial.println(hexValue);

  colorConverter(hexValue);

  if(flag_luces)
  {
     for(int i = 0; i < PIXEL_COUNT; i++){
    neopixel1.setPixelColor(i, neopixel1.Color(r,g,b));
    neopixel2.setPixelColor(i, neopixel2.Color(r,g,b));
  }
  neopixel1.show();
  neopixel2.show();
  }
}


void colorConverter(String hexValue)
{
  int number = (int)strtol(&hexValue[0], NULL, 16);

  r = number >> 16& 0xFF;
  g = number >> 8 & 0xFF;
  b = number >> 0 & 0xFF;

  Serial.println("red is");
  Serial.println(r);
  Serial.println("green is");
  Serial.println(g);
  Serial.println("blue is");
  Serial.println(b);  
}

void funcion_intensidad_luces(AdafruitIO_Data *data)
{
  Serial.println("Cambio de intensidad de la luces");
  int x = data ->toInt();
  int intensidad = 20;
  Serial.println(x);
  intensidad = x;
  if(flag_luces)
  {
    neopixel1.setBrightness(intensidad);
    neopixel2.setBrightness(intensidad);
    neopixel1.show();
    neopixel2.show();
  }
}
