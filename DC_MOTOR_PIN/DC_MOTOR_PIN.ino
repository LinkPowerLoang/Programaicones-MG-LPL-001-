#define DC_MOTOR_PIN 3
int i = 0;

void setup() 
{
pinMode(DC_MOTOR_PIN,OUTPUT);
}

void loop() 
{
for (int i = 0; i< 255; i = i +64)
 {
  analogWrite (DC_MOTOR_PIN, i);
  delay (500);
 }
 for (int i = 255; i> 0; i = i -64)
 {
  analogWrite (DC_MOTOR_PIN, i);
  delay (500);
 }
  analogWrite (DC_MOTOR_PIN, 0);
  delay (500);
}
