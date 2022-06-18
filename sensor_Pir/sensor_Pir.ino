int sensorPir = 11;
int led = 9;
int datoPir;

void setup() 
{
 Serial.begin (9600);
 pinMode (sensorPir, INPUT);
 pinMode (led, OUTPUT);
}

void loop() 
{
 datoPir = digitalRead(sensorPir);
 if (datoPir == HIGH)
 {
  Serial.println("Alerta se dectecto movimiento");
  digitalWrite(led, HIGH);
 }
 else
 {
  Serial.println("Sistema bajo control");
  digitalWrite(led, LOW); 
 }
 delay(10);
}
