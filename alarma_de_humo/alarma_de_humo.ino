/*
Selecion Nacional de Robotica 2020
Porgamacion de :
Mateo Garcia
Nesthor Guillermo 
Septiembre 2020
*/

// Declaración de los pines
int sensor=0;
int LedRojo=11;
int LedAmarillo=12;
int LedVerde=13;
int Alarma=10;

void setup()//Declaración de entradas y salidas
{
  Serial.begin(9600);  // para usar el monitor serial
  pinMode(LedRojo,OUTPUT);//OUTPUT = SALIDA
  pinMode(LedAmarillo,OUTPUT);
  pinMode(LedVerde,OUTPUT);
  pinMode(Alarma,OUTPUT);
}

void loop()//Proceso a realizar 
{
  sensor = analogRead(A5);//leer datos del sensor
  Serial.print("Lectura del sensor: ");//Que este mensaje aparezca
  Serial.println(sensor); // Monitor serial
  
  if (sensor<930)// si los datos son realizados hacer esta función
   {
    digitalWrite(LedVerde,HIGH);// HIGH = Estado alto
    digitalWrite(LedAmarillo,LOW);// LOW = Estado bajo 
    digitalWrite(LedRojo,LOW);
    noTone(Alarma);// para no sonar el buzzer 
    Serial.println("Estado: Seguro");//impresión del monitor serial
   }
  
  if ((sensor>930) and (sensor<960))/* si los datos son realizados hacer esta función                                  */ 
   {
    digitalWrite(LedVerde,LOW);
    digitalWrite(LedAmarillo,HIGH);
    digitalWrite(LedRojo,LOW);
    noTone(Alarma);
    Serial.println("Estado:Cuidado");
   }
      
   if (sensor>960)//si los datos son realizados hacer esta función
   {
    digitalWrite(LedVerde,LOW);
    digitalWrite(LedAmarillo,LOW);
    digitalWrite(LedRojo,HIGH);
    tone(Alarma,440);
    delay(500);
    noTone(Alarma);
    Serial.println("Estado: Peligro");
    }  
  delay(1000);
}
// verificar que todos las llaves estén en su lugar
