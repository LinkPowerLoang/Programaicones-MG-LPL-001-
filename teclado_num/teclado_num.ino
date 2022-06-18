#include <Keypad.h>
const byte numRows = 4; // numero de filas
const byte numCols = 4; // numero de columnas

//Definiendo las teclas de mimmatriz 

char keymap [numRows][numCols]
{ 
 {'1','2','3','A',},
 {'4','5','6','B',},
 {'7','8','9','C',},
 {'*','0','#','D',},
};

//configuracion de pines de teclado con arduino
byte rowPins[numRows]= {11,10,9,8};//pines de fila
byte colPins[numCols]= {7,6,5,4,};//pines de columnas 

//iniciacion y configuracion de teclado 
Keypad teclado = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
 
void setup() 
{
 Serial.begin(9600);// comunicacion serial
}

void loop() 
{
 char key = teclado.getKey(); // declaracion de variables asignado por el tecaldo 
  if (key) // validacion de la lectura del teclado
  {
    Serial.println (key); // salida de informacion en el monitor serial 
  }
}
