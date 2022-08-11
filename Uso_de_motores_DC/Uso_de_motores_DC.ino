// Codigo generado para pruebas del kit gec 2021
// Basado en el ejemplo de adafruit 

// Libreria del Motor 
#include <T_DRV8833.h>

//Crear instancia de nuestra libreria
T_DRV8833 gecDriver = T_DRV8833();

//Pines para motores en kit GEC 2021
const int inputA1 = 13;
const int inputA2 = 15;
const int inputB1 = 2;
const int inputB2 = 4;

// Definir velocidad del motor 
int velocidad = 128;

//Definir retraso de tiempo entre pruebas
int tiempoPruebas = 4000;

void setup() {
//Activas el monitor serial
Serial.begin(115200);

//Vincular pines con motor de GEC 2021 KIT board
gecDriver.vincularMotor1(inputA1, inputA2);
gecDriver.vincularMotor2(inputB1, inputB2);
Serial.println("Motores Listo!");
}

void loop() {
  Serial.println("Motor hacia adelante en formato digital");
  gecDriver.motor1Adelante();
  gecDriver.motor2Adelante();
  delay(tiempoPruebas);

  Serial.println("Detener Motor");
  gecDriver.motor1Stop();
  gecDriver.motor2Stop();
  delay(tiempoPruebas);

  Serial.println("Motor hacia atrás en formato digital");
  gecDriver.motor1Atras();
  gecDriver.motor2Atras();
  delay(tiempoPruebas);

  Serial.println("Detener Motor");
  gecDriver.motor1Stop();
  gecDriver.motor2Stop();
  delay(tiempoPruebas);

  Serial.println("Motor hacia adelante en formato análogo");
  for (int i = 75; i < 256; i=i+2){
  gecDriver.motor1Adelante(i);
  gecDriver.motor2Adelante(i);
  Serial.println("Valor PWM:");
  Serial.println(i);
  delay(tiempoPruebas/16);
  }
  
  //Permitir correr el motor a un tiempo extra a máxima velocidad
  gecDriver.motor1Adelante(255);
  gecDriver.motor2Adelante(255);
  delay(tiempoPruebas);

  Serial.println("Detener Motor");
  gecDriver.motor1Stop();
  gecDriver.motor2Stop();
  delay(tiempoPruebas);

  Serial.println("Motor hacia atás en formato análogo");
  for (int i = 75; i < 256; i=i+2){
  gecDriver.motor1Atras(i);
  gecDriver.motor2Atras(i);
  Serial.println("Valor PWM:");
  Serial.println(i);
  delay(tiempoPruebas/16);
  }

  //Permitir correr el motor a un tiempo extra a máxima velocidad
  gecDriver.motor1Atras(255);
  gecDriver.motor2Atras(255);
  delay(tiempoPruebas);

  Serial.println("Detener Motor");
  gecDriver.motor1Stop();
  gecDriver.motor2Stop();
  delay(tiempoPruebas/4);
}
