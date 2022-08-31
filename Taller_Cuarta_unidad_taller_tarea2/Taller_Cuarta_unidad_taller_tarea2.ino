int foco_100 = 13;

void setup() {
  Serial.begin (9600);
  pinMode(foco_100,OUTPUT);
}

void loop() {
  
  if (Serial.available()> 0){
    int Dato = Serial.read();
    if (Dato=='1'){
      digitalWrite(foco_100,HIGH);
    }else if (Dato=='0'){
      digitalWrite(foco_100,LOW);
    }
  }

}
