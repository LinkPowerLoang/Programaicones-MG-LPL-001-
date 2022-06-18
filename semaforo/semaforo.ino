int  B = 13;
int  C = 12;
int  verde = 11;
int  rojo = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
}

void loop()
{
  
  if (Serial.available())
  {
    valor = Serial.read();
  }
   if (valor == "A")
   {
     digitalWrite(B, HIGH);
     digitalWrite(C, LOW);
     digitalWrite(verde, LOW);
     digitalWrite(rojo, HIGH);
     delay (3000);
     digitalWrite(verde; HIGH);
     delay (3000);
  }
}
