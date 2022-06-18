#include <ESP32Servo.h>

#include <GEC_DRV8833.h>
GEC_DRV8833 gecDriver = GEC_DRV8833();

#include <WiFi.h>
#include <SPI.h>
const char* ssid = "Familia_G-Ch";
const char* password = "FamiliK.13";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 50);
String readString;

int ledPin = 26; 
int ledPin1 = 27; 
int ledPin2 = 32; 
int ledPin3 = 2; 

const int inputA1 = 12;//Pines para motores en kit GEC 2021
const int inputA2 = 14;//Pines para motores en kit GEC 2021
const int inputB1 = 33;//Pines para motores en kit GEC 2021
const int inputB2 = 25;//Pines para motores en kit GEC 2021

Servo miServo;
#define servoPin 13

WiFiServer server(80);

void setup() {
   vincularMotores();
   
   miServo.attach(servoPin);
   miServo.write(160);
   
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin, OUTPUT);   
  digitalWrite(ledPin, LOW);

  pinMode(ledPin1, OUTPUT);    
  digitalWrite(ledPin1, LOW);

  pinMode(ledPin2, OUTPUT);   
  digitalWrite(ledPin2, LOW);

  pinMode(ledPin3, OUTPUT);    
  digitalWrite(ledPin3, LOW);


  // Conectarse a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Iniciar el servidor
  server.begin();
  Serial.println("Server started");

  // Imprimir la dirección IP
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // Comprueba si cliente se ha conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Espera hasta que el cliente envíe algunos datos.
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Lee la primera línea requerida
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Coincide con la solicitud
//ADELANTE
  int value0 = HIGH;
  if (request.indexOf("A") != -1)  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    motoresAdelante();
    miServo.write(160);
    value0 = HIGH;
  }
  //DETENIDO
  if (request.indexOf("0") != -1)  {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    stopMotoresAdelante();
    stopMotoresAtras();
    miServo.write(0);
    value0 = LOW;
  }

// ATRAS
    int value1 = HIGH;
  if (request.indexOf("B") != -1)  {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    motoresAtras();
    miServo.write(160);
  }

  // Derecha
    int value2 = HIGH;
  if (request.indexOf("C") != -1)  {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    girarRoverDer();
    miServo.write(160);
  }

  // Izquierda
    int value3 = HIGH;
  if (request.indexOf("D") != -1)  {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    girarRoverIzq(); 
    miServo.write(160);
  }
}

void vincularMotores(){
  // Vincular pines con motores de GEC 2021 KIT Board
  gecDriver.vincularMotor1(inputA1, inputA2);
  gecDriver.vincularMotor2(inputB1, inputB2);
  Serial.println("Motores listos para acción!");
}

void motoresAdelante(){
  Serial.println("Motores hacia adelante");
  gecDriver.motor1Adelante(255);
  gecDriver.motor2Adelante(255);
}

void motoresAtras(){
  Serial.println("Motores hacia atrás");
  gecDriver.motor1Atras(255);
  gecDriver.motor2Atras(255);
}

void stopMotoresAdelante(){
  Serial.println("Detener motores");
  gecDriver.motor1StopAd();
  gecDriver.motor2StopAd();
}

void stopMotoresAtras(){
  Serial.println("Detener motores");
  gecDriver.motor1StopAt();
  gecDriver.motor2StopAt();
}

void girarRoverIzq(){
  Serial.println("Girando rover izquierda");
  gecDriver.motor1Adelante(255);
  gecDriver.motor2Atras(255);
}

void girarRoverDer(){  
  Serial.println("Girar rover derecha");
  gecDriver.motor1Atras(255);
  gecDriver.motor2Adelante(255);
}
