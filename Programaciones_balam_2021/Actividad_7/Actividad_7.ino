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

const int offsetB = 1;

Motor motor = Motor(BIN1, BIN2, PWMB, offsetB, 0, 5000, 8, 2);

#include <EasyBuzzer.h>
int BUZZER_PIN = 27;

#define IO_USERNAME  "LinkPowerLoang"
#define IO_KEY       "aio_JmPf03aQW9nzpDnUysnCv9oK2vtH"

#define WIFI_SSID       "Familia_G-Ch"
#define WIFI_PASS       "FamiliK.13"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *ventilador = io.feed("ventilador");
AdafruitIO_Feed *intensidad_ventilador = io.feed("intensidad_motor");
AdafruitIO_Feed *luces = io.feed("luces");
AdafruitIO_Feed *hexcolor = io.feed("hexcolor");
AdafruitIO_Feed *alarma = io.feed("alarma");

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

  ventilador ->onMessage(funcion_ventilador);
  intensidad_ventilador ->onMessage(funcion_intensidad_ventilador);
  luces ->onMessage(funcion_luces);
  hexcolor ->onMessage(funcion_hexcolor);
  alarma ->onMessage(funcion_alarma);      
}

void loop() {
 io.run();
  
 float Temp = sensor.readTemperature();
  float hume = sensor.readHumidity();

  //isnan -> is not a number?
  if(isnan(Temp)){
    //Serial.println("Error al obtener temperatura");
  }else{
   // Serial.print("Temperatura *C = ");
    //Serial.println(temp);
    //tempIO-> save(temp);
  }

  //! isnan -> is not not a number? -> is a number?
  if(!isnan(hume)){
    //Serial.print("Humedad % = ");
    //Serial.println(hume);
    //humeIO->save(hume);
  }else{
    //Serial.println("Error al obtener humedad");
  }
  Serial.println();
  delay(1000);
}
  int flag_ventilador = 0;
  int velocidad = 20;
void funcion_ventilador(AdafruitIO_Data *data)
  {
    Serial.println("Funcion de ventilador");
    if (flag_ventilador)
    {
      brake(motor, motor);
      flag_ventilador =0;
    }
    else
    {
      forward(motor, motor, velocidad);
      flag_ventilador = 1;
    }
  }

void funcion_intensidad_ventilador(AdafruitIO_Data *data)
{
  Serial.println("Cambio de intensidad del ventilador");
  int x = data ->toInt();
  Serial.println(x);
  velocidad = x;
  


        for(int i = 0; i < PIXEL_COUNT; i++)
    {
      neopixel1.setPixelColor(i, neopixel1.Color(x,x,x));
      neopixel2.setPixelColor(i, neopixel2.Color(x,x,x));
      delay(100);
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

int flag_alarma = 0;
void funcion_alarma(AdafruitIO_Data *data)
{
  Serial.println("Funcion de alarma");
  if (flag_alarma)
  {
    EasyBuzzer.stopBeep();
    flag_alarma = 0;   
  }
  else
  {
    EasyBuzzer.beep(1000);
    flag_alarma = 1;
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
