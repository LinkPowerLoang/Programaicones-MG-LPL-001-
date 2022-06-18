#include <Stepper.h> 
//Velocida total 360º = 2048 
double stepsPerRevolution = 2048;

double stepsPerRevolution1 = 0; // 0 

double stepsPerRevolution10 = 104; // 10º
double stepsPerRevolutionM10 = -104; // 10º

double stepsPerRevolution20 = 156;// 20º
double stepsPerRevolutionM20 = -156;// 20º

double stepsPerRevolution30 = 208; //30º
double stepsPerRevolutionM30 = -208;// 30º

double stepsPerRevolution40 = 260; //40º
double stepsPerRevolutionM40 = -260;// 40º

double stepsPerRevolution50 = 312; // 50º 
double stepsPerRevolutionM50 = -312;// 60º

double stepsPerRevolution60 = 364; // 60º
double stepsPerRevolutionM60 = -364;// 60º

double stepsPerRevolution70 = 416; // 70º
double stepsPerRevolutionM70 = -416;// 70º

double stepsPerRevolution80 = 468; // 80º
double stepsPerRevolutionM80 = -468;// 80º

double stepsPerRevolution90 = 512; // 90º
double stepsPerRevolutionM90 = -512;// 90º

int Comando_entrada; 
int motSpeed = 10; 
                                                                //IN1,IN3,IN2,IN4
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Pin inversion to make the library work

void setup() {
  Serial.begin(9600);
 myStepper.setSpeed(motSpeed);
}

void loop() {
  if (Serial.available()>0){
    Comando_entrada = Serial.read();
    Motor0 ();
    Motor10 ();
    Motor20 ();
    Motor30 ();
    Motor40 ();
    Motor50 ();
    Motor60 ();
    Motor70 ();
    Motor80 ();
    Motor90 ();
  }
}

   //Motores
void Motor0 (){
 if (Comando_entrada == '0' )  {
     Serial.println("Motor en = 0º"); 
    myStepper.step(stepsPerRevolution1);  
    delay(1000); 
  }
}
void Motor10 (){
 if (Comando_entrada == '1' )  {
     Serial.println("Motor en = 10º"); 
    myStepper.step(stepsPerRevolution10);  
    delay(1000); 
    myStepper.step(stepsPerRevolutionM10);  
    delay(1000); 
  }
}

void Motor20 (){
 if (Comando_entrada == '2' )  {
     Serial.println("Motor en = 20º"); 
    myStepper.step(stepsPerRevolution20);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution20);
    delay(1000);   
  }
}

void Motor30 (){
 if (Comando_entrada == '3' )  {
     Serial.println("Motor en = 30º"); 
    myStepper.step(stepsPerRevolution30);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution30);
    delay(1000);   
  }
}

void Motor40 (){
 if (Comando_entrada == '4' )  {
     Serial.println("Motor en = 40º"); 
    myStepper.step(stepsPerRevolution40);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution40);
    delay(1000);   
  }
}

void Motor50 (){
 if (Comando_entrada == '5' )  {
     Serial.println("Motor en = 50º"); 
    myStepper.step(stepsPerRevolution50);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution50);
    delay(1000);   
  }
}

void Motor60 (){
 if (Comando_entrada == '6' )  {
     Serial.println("Motor en = 60º"); 
    myStepper.step(stepsPerRevolution60);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution60);
    delay(1000);   
  }
}

void Motor70 (){
 if (Comando_entrada == '7' )  {
     Serial.println("Motor en = 70º"); 
    myStepper.step(stepsPerRevolution70);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution70);
    delay(1000);   
  }
}

void Motor80 (){
 if (Comando_entrada == '8' )  {
     Serial.println("Motor en = 80º"); 
    myStepper.step(stepsPerRevolution80);  
    delay(1000); 
    myStepper.step(-stepsPerRevolution80);  
    delay(1000); 
  }
}

void Motor90 (){
 if (Comando_entrada == '9' )  {
     Serial.println("Motor en = 90º"); 
    myStepper.step(stepsPerRevolution90);  
    delay(1000); 
   myStepper.step(-stepsPerRevolution90);  
   delay(1000); 
  }
}
