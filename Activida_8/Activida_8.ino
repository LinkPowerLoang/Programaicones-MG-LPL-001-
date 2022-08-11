#include <Wire.h> 
#include <Adafruit_NeoPixel.h>

#define PIXEL_COUNT 4
#define PIXEL_PIN_1 15
#define PIXEL_PIN_2 13

Adafruit_NeoPixel neopixel1(PIXEL_COUNT, PIXEL_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neopixel2(PIXEL_COUNT, PIXEL_PIN_2, NEO_GRB + NEO_KHZ800);

#include <EasyBuzzer.h>
int BUZZER_PIN = 27;
int sensorPir = 17;
int datoPir;

void setup() 
{
 Serial.begin (115200);
 pinMode (sensorPir, INPUT);
 EasyBuzzer.setPin(BUZZER_PIN);
 Wire.begin(21, 22);
}

void loop() 
{
 datoPir = digitalRead(sensorPir);
 if (datoPir == HIGH)
 {
  Serial.println("Alerta se dectecto movimiento");
  
      for(int i = 0; i < PIXEL_COUNT; i++)
    {
      neopixel1.setPixelColor(i, neopixel1.Color(0,0,255));
      neopixel2.setPixelColor(i, neopixel2.Color(0,0,255));
    }
      neopixel1.show();
      neopixel2.show();
      EasyBuzzer.beep(1000);

 }
 else
 {
  Serial.println("No se encontor movimiento ");
      for(int i = 0; i < PIXEL_COUNT; i++)
    {
      neopixel1.setPixelColor(i, neopixel1.Color(0,0,0));
      neopixel2.setPixelColor(i, neopixel2.Color(0,0,0));
    }
      neopixel1.show();
      neopixel2.show();
      EasyBuzzer.stopBeep();
 }
 delay(100);
}
