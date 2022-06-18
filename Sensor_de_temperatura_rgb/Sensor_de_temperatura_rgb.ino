int led_rojo = 13;
int led_azul = 12;
int led_verde = 11;
int medidor = A0;
int led_rojo2 = 10;
int led_azul2 = 9;
int led_verde2 = 8;
int medidor2 = A1;
int buzzer = 7;

void setup() 
{
  pinMode(led_rojo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(medidor, INPUT);
  
  pinMode(led_rojo2, OUTPUT);
  pinMode(led_azul2, OUTPUT);
  pinMode(led_verde2, OUTPUT);
  pinMode(medidor2, INPUT);
  
  pinMode(buzzer, OUTPUT);
}


void loop() 
{
  float temperatura = analogRead(medidor);
  float temperatura2 = analogRead(medidor2);
  float milivoltios = (temperatura / 1023)*1500;
  float milivoltios2 = (temperatura2 / 1023)*1500;
  temperatura = milivoltios/10;
  temperatura2 = milivoltios2/10;
  
  if (temperatura < 10)
  {
    digitalWrite(led_rojo, LOW); 
    digitalWrite(led_verde, LOW);
    digitalWrite(led_azul, HIGH); 
    digitalWrite(buzzer, LOW);
  }
      else if (temperatura > 10&& temperatura < 25)
   {
    digitalWrite(led_rojo, LOW); 
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_azul, LOW);
    digitalWrite(buzzer, LOW);
  }
     else 
  {
    digitalWrite(led_rojo, HIGH); 
    digitalWrite(led_verde, LOW);
    digitalWrite(led_azul, LOW);
    digitalWrite(buzzer, HIGH);
  }
      if (temperatura2 < 10)
  {
    digitalWrite(led_rojo2, LOW); 
    digitalWrite(led_verde2, LOW);
    digitalWrite(led_azul, HIGH); 
    digitalWrite(buzzer, LOW);
  }
 
      else if (temperatura2 > 10&& temperatura2 < 25)
   {
    digitalWrite(led_rojo2, LOW); 
    digitalWrite(led_verde2, HIGH);
    digitalWrite(led_azul2, LOW);
    digitalWrite(buzzer, LOW);
   }
   else 
   {
    digitalWrite(led_rojo2, HIGH); 
    digitalWrite(led_verde2, LOW);
    digitalWrite(led_azul2, LOW);
    digitalWrite(buzzer, HIGH);
   }
}
