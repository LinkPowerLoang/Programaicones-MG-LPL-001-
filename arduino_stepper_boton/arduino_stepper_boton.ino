#include <Stepper.h> 
double stepsPerRevolution = 2048;
double stepsPerRevolution1 = 1070;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Pin inversion to make the library work

int botton_1 = A0;
int botton_2 = A1;
int botton_3 = A2;
int botton_4 = A3;
int valor1 = 0;
int valor2 = 0;
int valor3 = 0;
int valor4 = 0;

void setup() { 
  myStepper.setSpeed(10);  
  Serial.begin(9600); 
  pinMode(botton_1, INPUT);
  pinMode(botton_2, INPUT);
  pinMode(botton_3, INPUT);
  pinMode(botton_4, INPUT);
  } 
  
  void loop() {  
  valor1 = digitalRead(botton_1);
  valor2 = digitalRead(botton_2);
  valor3 = digitalRead(botton_3);
  valor4 = digitalRead(botton_4);
  
     if (valor1 == HIGH)
   {
    Serial.println("0 a 180 "); 
    Serial.print("Boton_1= ");
    Serial.println(valor1);      
    myStepper.step(stepsPerRevolution1);  
    delay(1000); 
   }

    if (valor2 == HIGH) 
    {
   Serial.println("180 a 0");  
   Serial.print("Boton_2= ");
   Serial.println(valor2);  
   myStepper.step(-stepsPerRevolution1); 
   delay(1000); 
    }
    if (valor3 == HIGH)
   {
    Serial.println("0 a 360"); 
    Serial.print("Boton_3= ");
    Serial.println(valor3);      
    myStepper.step(stepsPerRevolution);  
    delay(1000); 
   }

    if (valor4 == HIGH) 
    {
   Serial.println("360 a 0");  
   Serial.print("Boton_4= ");
   Serial.println(valor4);  
   myStepper.step(-stepsPerRevolution); 
   delay(1000); 
    }
}
