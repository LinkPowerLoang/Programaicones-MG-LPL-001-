#include <Wire.h> 
#include <Adafruit_NeoPixel.h>

#define PIXEL_COUNT 4
#define PIXEL_PIN_1 15
#define PIXEL_PIN_2 13

Adafruit_NeoPixel neopixel1(PIXEL_COUNT, PIXEL_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neopixel2(PIXEL_COUNT, PIXEL_PIN_2, NEO_GRB + NEO_KHZ800);

void setup() 
{
  Serial.begin(115200);
  Wire.begin(21, 22); 
}

void loop() 
{
  
  for (int l=0; l<255; l=l+5)
{
  
    for(int i = 0; i < PIXEL_COUNT; i++)
    {
      neopixel1.setPixelColor(i, neopixel1.Color(0,0,l));
      neopixel2.setPixelColor(i, neopixel2.Color(0,0,l));
      delay(100);
    }
      neopixel1.show();
      neopixel2.show();
      Serial.println(l);
      delay(100);
  }
    for (int l=225; l>0; l=l-5)
{
  
    for(int i = 0; i < PIXEL_COUNT; i++)
    {
      neopixel1.setPixelColor(i, neopixel1.Color(0,0,l));
      neopixel2.setPixelColor(i, neopixel2.Color(0,0,l));
      delay(100);
    }
      neopixel1.show();
      neopixel2.show();
      Serial.println(l);
      delay(100);
  }
}
