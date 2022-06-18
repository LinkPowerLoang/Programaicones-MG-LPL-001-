int sensorGas = A0;
int buzzer = 13;
int valor = 0;

void setup()
{
 Serial.begin (9600);
 pinMode(sensorGas, INPUT);
 pinMode(buzzer, OUTPUT);
 }

void loop() 
{
valor = analogRead(sensorGas);
Serial.print("Medicion de gas: ");
Serial.println(valor);

if (valor >=600)
  {
  tone(buzzer, 510,200);
  delay(100); 
  }
}
