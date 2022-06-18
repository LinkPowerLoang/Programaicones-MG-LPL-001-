     #include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(2,0);
  lcd.print("Jordan "); 
  lcd.setCursor (8,1);
  lcd.print("Garcia");
}
void loop() { 
  lcd.display();
}
