int led_rojo = 13;
int led_naranja = 12;
int led_azul = 11;
int medidor = A0;

void setup() 
{
  pinMode(led_rojo, OUTPUT);
  pinMode(led_naranja, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(medidor, INPUT);
}

void loop() 
{
  float temperatura = analogRead(medidor);
  float milivoltios = (temperatura / 1023)*1500;
  temperatura = milivoltios/10;
  
  if (temperatura < 10)
  {
    digitalWrite(led_rojo, LOW); 
    digitalWrite(led_naranja, LOW);
    digitalWrite(led_azul, HIGH); 
  }
  
  else if (temperatura > 10&& temperatura < 25)
   {
    digitalWrite(led_rojo, LOW); 
    digitalWrite(led_naranja, HIGH);
    digitalWrite(led_azul, LOW);
   }
   else 
   {
    digitalWrite(led_rojo, HIGH); 
    digitalWrite(led_naranja, LOW);
    digitalWrite(led_azul, LOW);
   }
}
