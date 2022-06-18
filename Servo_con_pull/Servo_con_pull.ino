#include <Servo.h>

Servo servo1;
Servo servo2;
int pull = 13;
int val;

void setup ()
{
    servo1.attach(5);
    servo2.attach(3);
    pinMode(pull, INPUT);
}

void loop ()
{
  val = digitalRead(pull);
  
    if (val==HIGH)
    {
      for (int i = 0; i <= 90; i++ )
      {
        servo1.write(i);
        servo2.write(i);
        delay(90);
      }
      delay(1000);
      
       for (int i = 90; i >= 0; i--)
      {
        servo1.write(i);
        servo2.write(i);
        delay(90);
      } 
    }
}
