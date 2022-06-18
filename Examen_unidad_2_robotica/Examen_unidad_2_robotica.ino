int sensor4 = 4;
int sensor3 = 5;
int sensor2 = 6;
int sensor1 = 7;

int rojo = 13;
int verde = 12;

int datoPir;

int motorA1 = 11;
int motorB1 = 10;
int motorA2 = 9;
int motorB2 = 8;
  
int motorD1 = 3;
int motorC1 = 2;
int motorC2 = 1;
int motorD2 = 0;


void setup() 
{
 pinMode (sensor1, INPUT);
 pinMode (sensor2, INPUT);
 pinMode (sensor3, INPUT);
 pinMode (sensor4, INPUT);
    
 pinMode (rojo, OUTPUT);
 pinMode (verde, OUTPUT);

 pinMode (motorA1, OUTPUT);
 pinMode (motorB1, OUTPUT);
 pinMode (motorC1, OUTPUT);
 pinMode (motorD1, OUTPUT);
 
 pinMode (motorA2, OUTPUT);
 pinMode (motorB2, OUTPUT);
 pinMode (motorC2, OUTPUT);
 pinMode (motorD2, OUTPUT);
}

void loop() 
{
  
//1 
 datoPir = digitalRead(sensor1);
 if (datoPir == HIGH)
 {
  digitalWrite(rojo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB2, LOW);
   delay (1000); 
 }
  
 else
 {
  digitalWrite(rojo, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB2, LOW);

 }
  
 //2 
 datoPir = digitalRead(sensor2);
 if (datoPir == HIGH)
 {
  digitalWrite(rojo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(motorC2, HIGH);
  digitalWrite(motorD2, LOW);
   delay (1000); 
 }
  
 else
 {
  digitalWrite(rojo, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(motorD2, LOW);
  digitalWrite(motorC2, LOW);
 }
  
 //3 
 datoPir = digitalRead(sensor3);
 if (datoPir == HIGH)
 {
  digitalWrite(rojo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorB1, LOW);
   delay (1000); 
 }
  
 else
 {
  digitalWrite(rojo, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorB1, LOW);
 }
  
 //4 
 datoPir = digitalRead(sensor4);
 if (datoPir == HIGH)
 {
  digitalWrite(rojo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(motorC1, HIGH);
  digitalWrite(motorD1, LOW);
   delay (1000); 
 }
  
 else
 {
  digitalWrite(rojo, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(motorC1, LOW);
  digitalWrite(motorD1, LOW);
 }
}
