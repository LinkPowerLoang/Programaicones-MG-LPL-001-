void setup(void) 
{
  Serial.begin(9600);
}
 
void loop(void) 
{
 
  float sensorVoltage; 
  float sensorValue;
  float uVindex;
  
  sensorValue = analogRead(A4);
  sensorVoltage = sensorValue/1024*5;
  uVindex = sensorVoltage/0.1;
  Serial.print("sensor reading = ");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  Serial.print("UV index = ");
  Serial.println(uVindex);
  Serial.println();
  delay(1000);
}
