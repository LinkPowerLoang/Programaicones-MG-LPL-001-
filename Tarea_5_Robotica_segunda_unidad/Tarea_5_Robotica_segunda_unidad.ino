//Pramacion De LDR BY Mateo Garcia
int LedRojo = 13;
int LedAmarrillo = 12;
int LedNaranja = 11;
int LedAzul = 10;
int LedBlanca = 9;

int sensorLDR = A0;
int valor = 0;

void setup() 
{
 Serial.begin(9600);
 pinMode(LedRojo, OUTPUT);
 pinMode(LedAmarrillo, OUTPUT);
 pinMode(LedNaranja, OUTPUT);
 pinMode(LedAzul, OUTPUT);
 pinMode(LedBlanca, OUTPUT);
  
 pinMode(sensorLDR, INPUT);
}


void loop() 
 {
  
 valor = analogRead(sensorLDR);
 Serial.print("Valor del Sensor LDR: ");
 Serial.println(valor);
 valorbajo();
 valorbajo1();
 valorMedio();
 valorMedio1();
 valorMedio2();
 valorAlto();
 delay(100);
}

void valorbajo(){
  if(valor<100){
  digitalWrite(LedRojo, HIGH);
  digitalWrite(LedAmarrillo, HIGH);
  digitalWrite(LedNaranja, HIGH);
  digitalWrite(LedAzul, HIGH);
  digitalWrite(LedBlanca, HIGH);  
  }
}

void valorbajo1(){
  if(valor>600){
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAmarrillo, HIGH);
  digitalWrite(LedNaranja, HIGH);
  digitalWrite(LedAzul, HIGH);
  digitalWrite(LedBlanca, HIGH);  
  }
}

void valorMedio(){
  if(valor>720){
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAmarrillo, LOW);
  digitalWrite(LedNaranja, HIGH);
  digitalWrite(LedAzul, HIGH);
  digitalWrite(LedBlanca, HIGH);  
  }
}

void valorMedio1(){
  if(valor>820){
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAmarrillo, LOW);
  digitalWrite(LedNaranja, LOW);
  digitalWrite(LedAzul, HIGH);
  digitalWrite(LedBlanca, HIGH);  
  }
}

void valorMedio2(){
  if(valor>880){
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAmarrillo, LOW);
  digitalWrite(LedNaranja, LOW);
  digitalWrite(LedAzul, LOW);
  digitalWrite(LedBlanca, HIGH);  
  }
}

void valorAlto(){
  if(valor>920){
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAmarrillo, LOW);
  digitalWrite(LedNaranja, LOW);
  digitalWrite(LedAzul, LOW);
  digitalWrite(LedBlanca, LOW);  
  }
}
