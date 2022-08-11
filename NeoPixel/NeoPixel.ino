// Codigo generado para pruebas del kit gec 2021
// Basado en el ejemplo de adafruit 

//Adafruit Neopixel library 
#include <Adafruit_NeoPixel.h>

//Pin de los NeoPixel
#define PIN 32

//Cuanto NeoPixel estan conectados
#define NUMPIXELS 1

//definicion de objeto
Adafruit_NeoPixel pixels (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Tiempo de retraso a utilizar
#define DELAYVAL 1000

//Intensidad de la NeoPixel
int brillo = 25;

void setup() {
  //Inicia el objeto a utilizar
  pixels.begin ();
  //Asignar el brillo
  pixels.setBrightness(brillo);
}

void loop() {
// Desactivar lo colores del NeoPixel
pixels.clear();
delay (1000);

//Colores usados RGB, 0,0,0, o 255,255,255

//Mostrar el color rojo
pixels.setPixelColor (0, pixels.Color(150,0,0));
//Mostrar el color 
pixels.show();
//Tiempo de mostrado de color
delay (DELAYVAL);

//Mostrar el color verde
pixels.setPixelColor (0, pixels.Color(0,150,0));
//Mostrar el color 
pixels.show();
//Tiempo de mostrado de color
delay (DELAYVAL);

//Mostrar el color azul
pixels.setPixelColor (0, pixels.Color(0,0,150));
//Mostrar el color 
pixels.show();
//Tiempo de mostrado de color
delay (DELAYVAL);

//Mostrar el color turquesa
pixels.setPixelColor (0, pixels.Color(48,150,75));
//Mostrar el color 
pixels.show();
//Tiempo de mostrado de color
delay (DELAYVAL);
}
