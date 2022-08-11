#include <analogWrite.h>

#define AIN1 32
#define AIN2 33 
#define BIN1 25
#define BIN2 26

void setup() {
  Serial.begin(9600);

  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

}

void loop() {
  //Prueba de PWM con 255
 Serial.println("Programacion 1");
 Serial.println("Velocidad de PWM con 255");
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,0);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,0);

 delay(1000);

 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,LOW);

  Serial.println("En espera........");
 delay(2000);

   //Prueba de PWM con 64
 Serial.println("Velocidad de PWM con 64");
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,64);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,64);

 delay(1000);

 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,LOW);

  Serial.println("En espera........");
 delay(2000);

 Serial.println("Cambio programacion........");
 delay(2000);

   //Prueba de PWM con 255
  Serial.println("Velocidad de PWM con 255");
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,0);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,0);

 delay(1000);

 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,255);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,255);

  Serial.println("En espera........");
 delay(2000);
}
