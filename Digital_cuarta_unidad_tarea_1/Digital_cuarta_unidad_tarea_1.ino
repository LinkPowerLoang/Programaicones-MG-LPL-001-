int pindig1_digital=32;
int pindig2_Led=33;
int pinana_analog=34;

void setup() {
  Serial.begin(115200);
  pinMode(pindig1_digital,INPUT);
  pinMode(pindig2_Led,OUTPUT);
}

void loop() {
 int val_digital;
 int val_analog;
 val_digital= digitalRead(pindig1_digital);
 val_analog= analogRead(pinana_analog);

 Serial.print("Sensor de Gas analogico =  ");
 Serial.println(val_analog);
 Serial.print("Sensor de Gas digital =  ");
 Serial.println(val_digital);

 if(val_analog>1000)
 {
  Serial.println("Gas");
  digitalWrite(pindig2_Led,HIGH);
  Serial.println("");
  delay(1500);
 }

 else
 {
  Serial.println("No hay Gas");
  digitalWrite(pindig2_Led,LOW);
  Serial.println("");
  delay(1500);
 }
  
}
