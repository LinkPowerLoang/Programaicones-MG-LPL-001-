#include<LiquidCrystal.h>
//Asignacion de pines utilizados en nuestro LED
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//indicacion a la libreria sobre los pines que utiliza
LiquidCrystal led (rs, en, d4, d5, d6, d7);
void setup()
{
  // indicamos que usaremos en led de 16x2
  led.begin(16,2);
}

void loop()
{
 led.setCursor(1,1);//ubicacion de nuestro cursos
 led.print ("Hola mundo");// mensaje que proyecta nuetra led
 delay(500);
 led.clear();//limpiar led
 led.setCursor(4,1);//ubicacion de nuestro cursos
 led.print ("4to baco");// mensaje que proyecta nuetra led
 delay(500);
 led.clear();//limpiar led

}
