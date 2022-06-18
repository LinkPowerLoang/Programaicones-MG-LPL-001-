int LED_1 = 13;
int LED_2 = 12;

int caracter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
}

void loop() {
    if(Serial.available()>0){
        caracter = Serial.read();
      } 
      if(caracter == 'C'){
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, LOW);
        caracter = 0;
        }
        
        if(caracter == 'M'){
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, HIGH);
        caracter = 0;
        }
        
        
        if(caracter == 'G'){
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        caracter = 0;
        }

        if(caracter == 'L'){
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        caracter = 0;
        }
}
