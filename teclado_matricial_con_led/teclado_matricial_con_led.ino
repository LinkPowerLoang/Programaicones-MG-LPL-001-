#include <Keypad.h>
const byte numRows = 4; 
const byte numCols = 4; 

char keymap [numRows][numCols]
{ 
 {'1','2','3','A',},
 {'4','5','6','B',},
 {'7','8','9','C',},
 {'*','0','#','D',},
};

byte rowPins[numRows]= {11,10,9,8};
byte colPins[numCols]= {7,6,5,4,};

Keypad teclado = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
 
int led = 3;

void setup() 
{
 Serial.begin(9600);
 pinMode (led, OUTPUT); 
}

void loop() 
{
 char key = teclado.getKey(); 
  if (key) 
  {
    Serial.println (key); 
  }
 if(key=='1')
  {
    digitalWrite(led,HIGH);
  }
    if(key=='2')
  {
    digitalWrite(led,LOW);
  }
}
