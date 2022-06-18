//Programacion de Mateo

#include <IRremote.h>
int sensorIR = 9;
int rojo = 7;
int azul = 6;
int verde = 5;

IRrecv irrecv(sensorIR);
decode_results resultados;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  if(irrecv.decode(&resultados))
  {
    Serial.println(resultados.value, HEX);
    irrecv.resume();
  //rojo  
    if(resultados.value == 0xFD08F7)
    {
      digitalWrite(rojo, HIGH); 
    }
    else if (resultados.value == 0xFD00FF)
   {
    digitalWrite(rojo, LOW);
   }
    //azul
        if(resultados.value == 0xFD8877)
    {
      digitalWrite(azul, HIGH); 
    }
    else if (resultados.value == 0xFD00FF)
   {
    digitalWrite(azul, LOW);
   }
    
    //verde
        if(resultados.value == 0xFD48B7)
    {
      digitalWrite(verde, HIGH); 
    }
    else if (resultados.value == 0xFD00FF)
   {
    digitalWrite(verde, LOW);
   }
 }
  delay(100);
}
