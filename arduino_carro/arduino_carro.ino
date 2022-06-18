
int ledPin = 8; 
int ledPin1 = 7; 
int ledPin2 = 6; 
int ledPin3 = 5; 
int buzzer = 4;

int motorA = 12;//Pines para motores en kit GEC 2021
int motorB = 11;//Pines para motores en kit GEC 2021
int motorC = 10;//Pines para motores en kit GEC 2021
int motorD = 9;//Pines para motores en kit GEC 2021


void setup() {
   
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin, OUTPUT);   
  digitalWrite(ledPin, LOW);

  pinMode(ledPin1, OUTPUT);    
  digitalWrite(ledPin1, LOW);

  pinMode(ledPin2, OUTPUT);   
  digitalWrite(ledPin2, LOW);

  pinMode(ledPin3, OUTPUT);    
  digitalWrite(ledPin3, LOW);
  
  pinMode(buzzer, OUTPUT);    
  digitalWrite(buzzer, LOW);
  
  pinMode(motorA, OUTPUT);   
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT);
  pinMode(motorD, OUTPUT);
}

void loop() {
  
 //ADELANTE
 
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(buzzer, LOW);
    motoresAdelante();
    delay(2000);

      // Derecha
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(buzzer, LOW);
    girarRoverDer();
    delay(2000);
   
  
  //DETENIDO
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(buzzer, LOW);
    stopMotores();
    delay(2000);

// ATRAS
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(buzzer, HIGH);
    motoresAtras();
    delay(2000);

  // Izquierda
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(buzzer, LOW);
    girarRoverIzq(); 
    delay(2000);
}


void motoresAdelante(){
  Serial.println("Motores hacia adelante");
  analogWrite(motorA, 255);
  analogWrite(motorB, 0);
  analogWrite(motorC, 255);
  analogWrite(motorD, 0);
}

void motoresAtras(){
  Serial.println("Motores hacia atrás");
  analogWrite(motorA, 0);
  analogWrite(motorB, 255);
  analogWrite(motorC, 0);
  analogWrite(motorD, 255);
}

void stopMotores(){
  Serial.println("Detener motores");
  analogWrite(motorA, 0);
  analogWrite(motorB, 0);
  analogWrite(motorC, 0);
  analogWrite(motorD, 0);
}

void girarRoverIzq(){
  Serial.println("Girando rover izquierda");
  analogWrite(motorA, 255);
  analogWrite(motorB, 0);
  analogWrite(motorC, 0);
  analogWrite(motorD, 255);
}

void girarRoverDer(){  
  Serial.println("Girar rover derecha");
  analogWrite(motorA, 0);
  analogWrite(motorB, 255);
  analogWrite(motorC, 255);
  analogWrite(motorD, 0);
}
