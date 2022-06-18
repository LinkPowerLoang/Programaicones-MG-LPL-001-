//Gamepad
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Liberia para PWM
#include <analogWrite.h>

//Definicion de pines
#define AIN1 32
#define AIN2 33 
#define BIN1 25
#define BIN2 26

//Disparador
#define AIN_1 18
#define AIN_2 4 

// Senosor IR
#define dataSensorIR 19

#define LED 13 

int tiempoPruebas = 100;

void setup() {
  //Activador monitor de serie
  Serial.begin(115200);
  //Nombre del la conexion del servidor de la esp32
  Dabble.begin("balam2022-MG");

  //Declaracion de pines de motor de movimiento
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

  //Declaracion de pines de motor de lanzadora
  pinMode(AIN_1,OUTPUT);
  pinMode(AIN_2,OUTPUT);

  //Declaracion de pin de sensor IR
  pinMode(dataSensorIR,INPUT);

  //Delaracion de las LED 
  pinMode(LED,OUTPUT);
}

void loop() {
  Serial.print("Datos Sensor IR");
  Serial.println(digitalRead(dataSensorIR));
  
  Dabble.processInput();//esta función se utiliza para actualizar los datos obtenidos del teléfono inteligente. Por lo tanto, llamar a esta función es obligatorio para obtener datos correctamente desde su teléfono móvil.
  Serial.print("Tecla presionada: ");
  if (GamePad.isUpPressed()) {
   Serial.print("Arriba"); 
    adelante();
  }

  if (GamePad.isDownPressed()) {
    Serial.print("Abajo");
    atras();
  }

  if (GamePad.isLeftPressed()) {
    Serial.print("Izquierda");
    izquierda();
  }

  if (GamePad.isRightPressed()) {
    Serial.print("Derecha");
    derecha();
  }

  if (GamePad.isSquarePressed()) {
    Serial.print("Cuadrado");
    activado_disparador();
  }

  if (GamePad.isCirclePressed()){
    Serial.print("Circulo"); 
    activado_subcionador();
  }

  if (GamePad.isCrossPressed()){
    Serial.print("Cruz");
    detener_disparadores();  
  }

  if (GamePad.isTrianglePressed()){
    Serial.print("Triagulo");

  }

  if (GamePad.isStartPressed()){
    Serial.print("Start");
    digitalWrite(LED,HIGH);
  }

  if (GamePad.isSelectPressed()){
    Serial.print("Select");
detener_todo();
  }

else{
 detener_movimineto();
    }
    
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angulo: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radio: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_eje: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_eje: ");
  Serial.println(d);
  Serial.println();
}

//Declaracion de acciones de los motores 
// Movimientos 
void adelante(){
 //Arriba
 digitalWrite(AIN1,HIGH);
 analogWrite(AIN2,50);
 digitalWrite(BIN1,HIGH);
 analogWrite(BIN2,0);
 delay(tiempoPruebas);
  }

void atras(){
//Abajo
 analogWrite(AIN1,50);
 digitalWrite(AIN2,HIGH);
 analogWrite(BIN1,50);
 digitalWrite(BIN2,HIGH);
 delay(tiempoPruebas);
  }

 void izquierda(){
//Izquierda
 analogWrite(AIN1,50);
 digitalWrite(AIN2,HIGH);
 digitalWrite(BIN1,HIGH);
 analogWrite(BIN2,50);
 delay(tiempoPruebas);
  }

 void derecha(){
//Derecha
 digitalWrite(AIN1,HIGH);
 analogWrite(AIN2,50);
 analogWrite(BIN1,50);
 digitalWrite(BIN2,HIGH);
 delay(tiempoPruebas);
  }

  
void detener_movimineto(){
//Detener motores
analogWrite(AIN1,255);
analogWrite(AIN2,255);
analogWrite(BIN1,255);
analogWrite(BIN2,255);
  }
  
// Disparadores   
void activado_disparador(){
//Activar Disparadores
digitalWrite(AIN_1,HIGH);
digitalWrite(AIN_2,LOW);
delay(tiempoPruebas);
  }
  
void activado_subcionador(){
//Activar Subcionador
digitalWrite(AIN_1,LOW);
digitalWrite(AIN_2,HIGH);
delay(tiempoPruebas);
  }  
  
void detener_disparadores(){
//Desactivar Disparador y Subcionador
digitalWrite(AIN_1,LOW);
digitalWrite(AIN_2,LOW);
delay(tiempoPruebas);
  }

 //Detener todo
 void detener_todo(){
 analogWrite(AIN1,255);
 analogWrite(AIN2,255);
 analogWrite(BIN1,255);
 analogWrite(BIN2,255);
 
 digitalWrite(AIN_1,LOW);
 digitalWrite(AIN_2,LOW);

 digitalWrite(LED,LOW);
 delay(tiempoPruebas);
  } 
