#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <analogWrite.h>

//Definicion de pines
#define AIN1 32
#define AIN2 33 
#define BIN1 25
#define BIN2 26

#define AIN_1 18
#define AIN_2 5

int valorPWMLantas = 100;
int tiempoPruebas = 100;

void setup() {
  Serial.begin(115200);
  Dabble.begin("balam2022-MG");

  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(AIN_1,OUTPUT);
  pinMode(AIN_2,OUTPUT);

}

void loop() {
  Dabble.processInput();             
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,LOW);
 delay(tiempoPruebas);
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,HIGH);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,HIGH);
 delay(tiempoPruebas);
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,HIGH);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,LOW);
 delay(tiempoPruebas);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,HIGH);
 delay(tiempoPruebas);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,HIGH);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,HIGH);
 digitalWrite(AIN_1,LOW);
 digitalWrite(AIN_2,LOW);
 delay(tiempoPruebas);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
 digitalWrite(AIN_1,HIGH);
 digitalWrite(AIN_2,LOW);
 
 delay(tiempoPruebas);
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();

}
