// Codigo generado para pruebas del kit gec 2021
// Basado en el ejemplo de adafruit 

//Pines en tarjeta GEC 2021 para sensores Sharp GP2Y0E02A
// Sharp J1 -> io33
// Sharp J2 -> io25
// Sharp J3 -> io26

// Definir pines para Sensores Sharp GP2Y0E02A
#define sensorDistanciaJ1 33
#define sensorDistanciaJ2 25
#define sensorDistanciaJ3 26

//Variables para leer estado del sensor de distancia
int estadoSensorDistanciaJ1= 0;
int estadoSensorDistanciaJ2= 0;
int estadoSensorDistanciaJ3= 0;

void setup() {
  // Activador del monitor serial
  Serial.begin(115200);
  
  //Definir configuracion de pines de entrada
  pinMode(sensorDistanciaJ1, INPUT);
  pinMode(sensorDistanciaJ2, INPUT);
  pinMode(sensorDistanciaJ3, INPUT);
}

void loop() {
  //Loop para leer y desplegar el estado del sensor Sharp GP2Y0E02A J1
  estadoSensorDistanciaJ1 = analogRead(sensorDistanciaJ1);
  Serial.print("Valor en sensor distancia J1 =");
  Serial.println(estadoSensorDistanciaJ1);

 //Loop para leer y desplegar el estado del sensor Sharp GP2Y0E02A J2
  estadoSensorDistanciaJ2 = analogRead(sensorDistanciaJ2);
  Serial.print("Valor en sensor distancia J2 =");
  Serial.println(estadoSensorDistanciaJ2);
  
 //Loop para leer y desplegar el estado del sensor Sharp GP2Y0E02A J3
  estadoSensorDistanciaJ3 = analogRead(sensorDistanciaJ3);
  Serial.print("Valor en sensor distancia J3 =");
  Serial.println(estadoSensorDistanciaJ3);
  
  delay (2000);
}
