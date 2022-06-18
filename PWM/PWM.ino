#define Motor_pin 3

void setup() 
{
 pinMode(Motor_pin, OUTPUT);

}

void loop()
{
 for (int i=0; i<255; i=i+5)
  {
    analogWrite (Motor_pin, i);
    delay (500);
  }

  for (int i=255; i>0;; i=i-5)
  {
    analogWrite (Motor_pin, i);
    delay (500);
}

}
