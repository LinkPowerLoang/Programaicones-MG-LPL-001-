#define dataSensorIR 19

void setup() {
  Serial.begin(9600);
  pinMode(dataSensorIR, INPUT);
}

void loop() {
  Serial.println("Dato Sensor IR: ");
  Serial.println(digitalRead(dataSensorIR));
  delay(1000);
}
