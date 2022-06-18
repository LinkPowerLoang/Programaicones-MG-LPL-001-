#include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

const byte numfilas = 4; 
const byte numcolumas = 4; 

char keymap [numfilas][numcolumas]
{ 
 {'1','2','3','A',},
 {'4','5','6','B',},
 {'7','8','9','C',},
 {'*','0','#','D',},
};

byte filasPines[numfilas]= {11,10,9,8};
byte columasPines[numcolumas]= {7,6,5,4,};

Keypad teclado = Keypad(makeKeymap(keymap), filasPines, columasPines, numfilas, numcolumas);


void setup() 
{
 Serial.begin(9600);
 lcd.begin(16, 2);
}

void loop() 
{
 char key = teclado.getKey(); 
 lcd.setCursor(0,0);
 lcd.print("El numero es:");
    
  if (key) 
  {
    Serial.println (key); 
    lcd.setCursor(14,1);
    lcd.print(key);
    delay (1000);
    lcd.clear();
  }
}
