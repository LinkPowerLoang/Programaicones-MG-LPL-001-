int Hall = 6;
int LED13 = 13;

void setup() 
{
 pinMode(Hall, INPUT);
 pinMode(LED13,OUTPUT);
}

void loop() 
{
  if(digitalRead(Hall)==HIGH)
  {
   digitalWrite(LED13, LOW);
  }
  else
  {
   digitalWrite(LED13,HIGH);
  }
}
