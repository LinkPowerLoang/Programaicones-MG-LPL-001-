int leds [] = {9, 10, 11, 12, 13};
int nElemenst = 0;

void setup() {
  Serial.begin(9600);
  nElemenst = sizeof(leds) / sizeof(int);
  for(int i = 0; i < nElemenst; i++){
     pinMode(leds[i], OUTPUT);
      }
}

void loop() {
  for(int i = 0; i < nElemenst; i++);{
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
    }
}
