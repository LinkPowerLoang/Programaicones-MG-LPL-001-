int led = 23;

void setup() {
  Serial.begin (9600);
  pinMode(led,OUTPUT);

}

void loop() {
  
  if (Serial.available()> 0){
    int Dato = Serial.read();
    if (Dato=='1'){
      digitalWrite(led,HIGH);
    }else if (Dato=='0'){
      digitalWrite(led,LOW);
    }
  }

}
