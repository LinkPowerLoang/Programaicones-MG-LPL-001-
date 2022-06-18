int x = 0;
int valorMax =1023;
int valor = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(A5, INPUT);
  
  Serial.begin(9600);
}


void loop()
{
  
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
 valor = analogRead(A5);
 Serial.println(valor);
 x = valorMax / 5; //204.6
  /*
  0-204      0 leds
  204 - 409  1 
  409 - 613  2
  613 - 818  3
  818 - 1023 4
  */
  
  if (valor >= x*4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  else if (valor >= x*3)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
    else if (valor >= x*2)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  }
    else if (valor >= x)
  {
    digitalWrite(2, HIGH);
  }
  
 delay(100);
}
