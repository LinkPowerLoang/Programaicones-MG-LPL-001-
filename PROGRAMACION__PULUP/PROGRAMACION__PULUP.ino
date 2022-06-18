const int led = 12;
const int boton = 13;
int valor = 0; 
void setup() 
{
  pinMode (led,OUTPUT);
  pinMode (boton,INPUT);
}

void loop() 
{
 valor = digitalRead(boton);
 if (valor == HIGH )
 {
 digitalWrite(led, HIGH);
 }
 else
 {
  digitalWrite(led, LOW);
 }
 
}
