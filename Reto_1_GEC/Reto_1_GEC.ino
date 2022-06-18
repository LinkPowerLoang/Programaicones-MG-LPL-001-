//Pantalla lcd
#include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

//Fotoresistor
int fotoresistor = A4; 
int valor = 0;

//Sensor Ultra Sonico
#define triggerEmisor 3
#define echoReceptor 2
int distancia;
int A = 11;
int B = 10;
int C = 9;
int D = 6;
int velocidadTotal = 255;
int velocidadLenta = 70;

void setup() {
  //Monitor Serial
Serial.begin(9600);
  
//Pantalla lcd
lcd.begin(16,2);

//Fotoresistor
  pinMode(fotoresistor, INPUT);

//Sensor Ultra Sonico
  pinMode(triggerEmisor, OUTPUT);
  pinMode(echoReceptor, INPUT);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

}

void loop() {
  
 //Fotoresistor
valor = analogRead(fotoresistor);
Serial.print ("Luz:");
Serial.println(valor);

  //Sensor Ultra Sonico
  digitalWrite(triggerEmisor, HIGH);
  digitalWrite(triggerEmisor, LOW);
  delayMicroseconds(10);
  distancia=pulseIn(echoReceptor,HIGH);
  distancia=distancia/52;
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm  ");
  
   //Pantalla lcd
 //Mostrar Fotoresistor
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print ("Luz: ");
 lcd.setCursor(5,0);
 lcd.print (valor);
 
 //Mostrar  Distancia de Ultrasonico  
 lcd.setCursor(0,1);
 lcd.print ("Distancia:");
 lcd.setCursor(11,1);
 lcd.print (distancia);
 lcd.setCursor(14,1);
 lcd.print ("cm");
 delay(2000);
 lcd.clear();

 if (valor <=400) {
    if (distancia> 10){
    analogWrite(A,velocidadTotal);
    analogWrite(B,0);
    analogWrite(C,velocidadTotal);
    analogWrite(D,0);  
    //Motores
 Serial.print("Motor:");
 Serial.println(velocidadTotal);
 Serial.println("   ");
 lcd.setCursor(0,1);
 lcd.print ("Motor:");
 lcd.setCursor(9,1);
 lcd.print (velocidadTotal);
 delay(2000);
 lcd.clear();
  }
  
else{
    analogWrite(A,velocidadLenta);
    analogWrite(B,0);
    analogWrite(C,velocidadLenta);
    analogWrite(D,0);  
  //Motores
 Serial.print("Motor:");
 Serial.println(velocidadLenta);
 Serial.println("   ");
 lcd.setCursor(0,1);
 lcd.print ("Motor:");
 lcd.setCursor(9,1);
 lcd.print (velocidadLenta);
 delay(2000);
 lcd.clear();
 }
}

if (valor > 400){
    analogWrite(A,0);
    analogWrite(B,velocidadTotal);
    analogWrite(C,0);
    analogWrite(D,velocidadTotal);  
    delay (4000);

   //Para parar el motor 
   while (valor >=401){
    
  //Pantalla lcd
 //Mostrar Fotoresistor
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print ("Luz: ");
 lcd.setCursor(5,0);
 lcd.print (valor);
 //Mostrar  Distancia de Ultrasonico  
 lcd.setCursor(0,1);
 lcd.print ("Distancia:");
 lcd.setCursor(11,1);
 lcd.print (distancia);
 delay(2000);
 lcd.clear();
//Motores
 lcd.setCursor(0,1);
 lcd.print ("Motor:");
 lcd.setCursor(7,1);
 lcd.print ("Detenidos");
 delay(2000);
 lcd.clear();
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
//Detenido todal
valor = analogRead(fotoresistor);
 if (valor <=400){
  break; }
    }
  }
}
