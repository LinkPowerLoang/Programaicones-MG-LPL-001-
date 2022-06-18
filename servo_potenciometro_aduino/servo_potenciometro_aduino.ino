 #include <Servo.h>
Servo servo;
int potenciometro = A0;
int val;

void setup ()
{
   servo.attach(9);
   Serial.begin(9600);
}
void loop ()
{
  val = analogRead(potenciometro);
  val = map(val, 0, 1023, 0, 180);
  servo.write(val); 
  Serial.println("EL VALOR DE LOS GRADOS ES DE");
  Serial.println(val);
  //delay(2000);
}
