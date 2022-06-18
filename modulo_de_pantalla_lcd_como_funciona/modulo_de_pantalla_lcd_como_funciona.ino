#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() { 
 lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("Liceo canadiense"); 
  lcd.setCursor (0,1);
  lcd.print("se une a la ");
  delay(5000);
   lcd.clear();
  delay(2000);
   lcd.setCursor(0,0);
  lcd.print("celebracion del "); 
  lcd.setCursor (0,1);
  lcd.print("bicentenario de ");
  delay(5000);
   lcd.clear();
  delay(2000);
   lcd.setCursor(0,0);
  lcd.print("nuestra bella "); 
  lcd.setCursor (0,1);
  lcd.print("Guatemala ");
  delay(5000);
   lcd.clear();
  delay(2000);
  lcd.setCursor(5,0);
  lcd.print("_ "); 
   lcd.setCursor(0,1);
  lcd.print("200 anos de "); 
   delay(5000);
   lcd.clear();
  delay(2000);
  lcd.setCursor (0,0);
  lcd.print("independencia");
  delay(5000);
   lcd.clear();
  delay(2000);
}
