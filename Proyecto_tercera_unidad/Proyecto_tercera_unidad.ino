#include <IRremote.h>
#include <Servo.h>

int sensorGas = A5;
int rojo = 13;
int azul = 12;
int verde = 11;
int valor = 0;

int sensorIR = 10;
int foco1 = 9;
int foco2 = 4;
Servo servo;

IRrecv irrecv(sensorIR);
decode_results resultados;

int foco3 = 7;
int sensorLDR = A1;
int valor2 = 0;

int buzzer= 5;
int fotodiodo= 6;

void setup() 
{
   Serial.begin (9600);
 pinMode(sensorGas, INPUT);
 pinMode(rojo, OUTPUT);
 pinMode(azul, OUTPUT);
 pinMode(verde, OUTPUT);

   irrecv.enableIRIn();
   pinMode(foco1, OUTPUT);
   pinMode(foco2, OUTPUT);
   servo.attach(8);

  pinMode(foco3, OUTPUT);
 pinMode(sensorLDR, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(fotodiodo, INPUT_PULLUP);
}

void loop() 
{
  //Sensor Gas
   valor = analogRead(sensorGas);
  Serial.print("Lectura del sensor: ");
  Serial.println(valor); 
  
  if (valor<400)
   {
    digitalWrite(verde,HIGH);
    digitalWrite(azul,LOW);
    digitalWrite(rojo,LOW);
    Serial.println("Estado: Seguro");
   }
  
  if ((valor>450) and (valor<500)) 
   {
    digitalWrite(verde,LOW);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,LOW);
    Serial.println("Estado:Cuidado");
   }
      
   if (valor>600)
   {
    digitalWrite(verde,LOW);
    digitalWrite(azul,LOW);
    digitalWrite(rojo,HIGH);
    Serial.println("Estado: Peligro");
    }  
  delay(1000);

  //Infrarojo
  if(irrecv.decode(&resultados))
  {
    irrecv.resume();
  //foco1  
    if(resultados.value == 0xFD08F7)
    {
      digitalWrite(foco1, HIGH); 
    }
    else if (resultados.value == 0xFD00FF)
   {
    digitalWrite(foco1, LOW);
   }
    //foco2
        if(resultados.value == 0xFD8877)
    {
      digitalWrite(foco2, HIGH); 
    }
    else if (resultados.value == 0xFD00FF)
   {
    digitalWrite(foco2, LOW);
   }
    
    //servo
        if(resultados.value == 0xFD48B7)
    {
      for (int pos = 0; pos <= 180; pos +=1 )
      {
        servo.write(pos);
        delay(10);
      }
      delay(1000);
     
      for (int pos = 180; pos >= 0; pos -=1 )
      {
        servo.write(pos);
        delay(10);
      }
    }
    else if (resultados.value == 0xFD00FF)
   {
        servo.write(0);
   }

 }
  delay(100);
  
  //LDR
   valor2 = analogRead(sensorLDR);
 if (valor2 <400)
 {
  digitalWrite(foco3, HIGH);
 }
 else
 {
  digitalWrite(foco3, LOW);
 }
  delay(200); 

  //fotodiode
  if (digitalRead(fotodiodo)== HIGH) 
  {
  digitalWrite(buzzer, HIGH);
     }
  else
    {
    digitalWrite(buzzer, LOW);
  }

}
