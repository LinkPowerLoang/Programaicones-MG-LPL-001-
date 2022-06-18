void setup() {
  Serial.begin(9600);

}

void loop() {
    Serial.println(analogRead(35));
    delay(500); 
}
