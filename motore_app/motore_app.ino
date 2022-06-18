#include "AdafruitIO_WiFi.h"
#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sensor = Adafruit_SHT31();

#include <TB6612_ESP32.h>

//MOTOR2
#define BIN1 25
#define BIN2 26
#define PWMB 14

const int offsetB = -1;

Motor motor = Motor(BIN1, BIN2, PWMB, offsetB, 0, 5000, 8, 2);

#define IO_USERNAME  "LinkPowerLoang"
#define IO_KEY       "aio_JmPf03aQW9nzpDnUysnCv9oK2vtH"

#define WIFI_SSID       "Familia_G-Ch"
#define WIFI_PASS       "FamiliK.13"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *ventilador = io.feed("ventilador");

void setup() 
{
   Serial.begin(115200);
   Wire.begin(21,22);
  if(sensor.begin(0x44))
  {
    Serial.println("Sensor encontrado");
  }
  else
  {
    Serial.println("Sensor NO encontrado");
    while(1)
    {
      delay(10);
    }
  }
   Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED)
  {
    Serial.println(io.statusText());
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  ventilador ->onMessage(funcion_ventilador);   
}

void loop() 
{
  
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
