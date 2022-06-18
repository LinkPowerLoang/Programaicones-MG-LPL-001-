int led = 12;
int sensorLDR = A0;
int valor = 0;

void setup() 
{
 Serial.begin(9600);
 pinMode(led, OUTPUT);
 pinMode(sensorLDR, INPUT);
}


void loop() 
 {
 valor = analogRead(sensorLDR);
 if (valor <400)
 {
  digitalWrite(led, HIGH);
  Serial.println ("Lus encendida");
  Serial.println(valor);
 }
 else
 {
  digitalWrite(led, LOW);
  Serial.println ("Lus a`pagada");
  Serial.println(valor);
 }
 delay (200);
}
