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

//Definision de los pines del Dip Swicht
#define DS1 27 //Dip Swicht #1
#define DS2 14 //Dip Swicht #2

//Variable para leer estado del dip swicht
int estadoDS1 = 0;
int estadoDS2 = 0;

void setup() {
  // Activador del monitor serial
  Serial.begin(115200);
  
  //Definir configuracion de pines de entrada
  pinMode(DS1, INPUT);
  pinMode(DS2, INPUT);

  //Inicia el objeto a utilizar
  pixels.begin ();
  //Asignar el brillo
  pixels.setBrightness(brillo);

  // Desactivar lo colores del NeoPixel
  pixels.clear();
  pixels.show();
  delay (1000);
}

void loop() {
//Loop para leer y desplegar el estado de DS1
  estadoDS1 = digitalRead(DS1);
  Serial.print("Valor en DS1 = ");
  Serial.println(estadoDS1);

//Loop para leer y desplegar el estado de DS2
  estadoDS2 = digitalRead(DS2);
  Serial.print("Valor en DS2 = ");
  Serial.println(estadoDS2);

  if((estadoDS1 == 1) && (estadoDS2 == 1)){
      pixels.clear();
      pixels.show();
      delay (2000);
    }

   if((estadoDS1 == 1) && (estadoDS2 == 0)){
      encenderRojo();
    }

   if((estadoDS1 == 0) && (estadoDS2 == 1)){
      encenderVerde();
    }

   if((estadoDS1 == 0) && (estadoDS2 == 0)){
      pixels.clear();
      pixels.show();
      delay (2000);
    }
  //Tiempo para distinguir los colores
  delay(2000);
}

void encenderRojo(){
//Mostrar el color rojo
pixels.setPixelColor (0, pixels.Color(150,0,0));
//Mostrar el color 
pixels.show();
//Tiempo de mostrado de color
delay (DELAYVAL);
  }

void encenderVerde(){
//Mostrar el color verde
pixels.setPixelColor (0, pixels.Color(0,150,0));
//Mostrar el color 
pixels.show();
//Tiempo de mostrado de color
delay (DELAYVAL);
  }
