#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal led (rs, en, d4, d5, d6, d7);
void setup()
{
  led.begin(16,2);
}

void loop()
{
 led.setCursor(0,0);
 led.print ("Bien venidos a");
 led.setCursor(0,1);
 led.print ("Liceo Canadiense");
 delay(2000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("Quieres estudiar");
 delay(2000);
 
 led.clear(); 
 led.setCursor(4,0);
 led.print ("4to Perito");
 led.setCursor(1,1);
 led.print ("En Electronica");
 delay(2000);
 
 led.clear();
 led.setCursor(4,0);
 led.print ("Materias");
 delay(2000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("1. Ciencias");
 led.setCursor(3,1);
 led.print ("Sociales");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("2. Comuncacion y");
 led.setCursor(0,1);
 led.print ("Lenguaje=Ingles");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("3. Diplomado en");
 led.setCursor(4,1);
 led.print ("Robotica");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("4. Educacion");
 led.setCursor(4,1);
 led.print ("Fisica");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("5. Electroma-");
 led.setCursor(8,1);
 led.print ("gnetismo");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("6. Electro");
 led.setCursor(3,1);
 led.print ("Analogica");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("7. Expresion");
 led.setCursor(3,1);
 led.print ("Artistica");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("8. Fisica");
 led.setCursor(3,1);
 led.print ("Fundametal");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("9. Lengua y");
 led.setCursor(3,1);
 led.print ("Literatura");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("10. Matematicas");
 led.setCursor(0,1);
 led.print ("11. Progrentis");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("12. Taller de");
 led.setCursor(3,1);
 led.print ("Analogica");
 delay(4000);
 
 led.clear();
 led.setCursor(0,0);
 led.print ("13.Tecnologia de");
 led.setCursor(0,1);
 led.print ("la Informacion");
 delay(4000);
 led.clear();
}
