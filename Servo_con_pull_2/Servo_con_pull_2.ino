#include <Servo.h>

Servo servo1;
Servo servo2;
int boton = 13;
int valor = 0;

void setup ()
{
   Serial.begin(9600);
    pinMode(boton, INPUT);
    servo1.attach(5);
    servo2.attach(3);
}

void loop ()
{
  
  valor = digitalRead(boton);
  
    if (valor==HIGH)
    {
      for (int pos = 0; pos <= 180; pos +=1 )
      {
        Serial.print("Sermotores anti horario");
        Serial.println(valor);
        servo1.write(pos);
        servo2.write(pos);
        delay(80);
      }
      delay(1000);
     
      for (int pos = 180; pos >= 0; pos -=1 )
      {
        Serial.print("Sermotores sentido horario");
        Serial.println(valor);
        servo1.write(pos);
        servo2.write(pos);
        delay(80);
      }
    }
    else
      {
        Serial.print("Sermotoresdetenido: ");
        Serial.println(valor);
        servo1.write(0);
        servo2.write(0);
      }
}
