int motorA =13;
int motorB =12;
int motorC =11;
int motorD =10;
int adelante =7;
int retroceso =6;
int izquierda =4;
int derecha =3; 


int valorA;
int valorB;
int valorC;
int valorD;


void setup() 
{
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(motorC,OUTPUT);
  pinMode(motorD,OUTPUT);
  pinMode(adelante, INPUT);
  pinMode(retroceso, INPUT);
  pinMode(izquierda, INPUT);
  pinMode(derecha, INPUT);
}

void loop() 
{
  valorA = digitalRead(adelante);
  valorB = digitalRead(retroceso);
  valorC = digitalRead(izquierda);
  valorD = digitalRead(derecha);


  if (valorA==HIGH)
  {
   digitalWrite(motorA,HIGH); 
   digitalWrite(motorB,LOW); 
   digitalWrite(motorC,HIGH); 
   digitalWrite(motorD,LOW); 
  }
  
    if (valorB==HIGH)
  {
   digitalWrite(motorA,LOW); 
   digitalWrite(motorB,HIGH); 
   digitalWrite(motorC,LOW); 
   digitalWrite(motorD,HIGH); 
  }
  
    if (valorC==HIGH)
  {
   digitalWrite(motorA,HIGH); 
   digitalWrite(motorB,LOW); 
   digitalWrite(motorC,LOW); 
   digitalWrite(motorD,LOW); 
  }
  
      if (valorD==HIGH)
  {
   digitalWrite(motorA,LOW); 
   digitalWrite(motorB,LOW); 
   digitalWrite(motorC,HIGH); 
   digitalWrite(motorD,LOW); 
  }
  
  else
  {
   digitalWrite(motorA,LOW); 
   digitalWrite(motorB,LOW); 
   digitalWrite(motorC,LOW); 
   digitalWrite(motorD,LOW);
   }
   
}
