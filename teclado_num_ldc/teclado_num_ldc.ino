#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (5, 4, 3, 2, A4, A5);

const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS][COLS]=
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowsPins[ROWS] = {A0, A1, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};
int LCDcol = 0;

Keypad keypad = Keypad (makeKeymap(keys), rowsPins, colPins, ROWS, COLS);

void setup() 
{
  Serial.begin (9600);
  lcd.begin(16, 2);
  lcd.setCursor(LCDcol, 0);
}

void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    Serial.println(key);
    lcd.print(key);
    lcd.setCursor(++LCDcol, 0);
   
  }
}
