#include <WiFi.h> // Libreria para placa ESP32
#include <SPI.h>
const char* ssid = "Familia_G-Ch";
const char* password = "FamiliK.13";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,50);
String readString; 

int ledPin = 26; 
int motorA = 14;
int motorB = 15;

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);   // Inicia LED rojo apagado
  digitalWrite(ledPin, LOW);
  
  pinMode(motorA , OUTPUT);   // Inicia salidas de motor apagado
  digitalWrite(motorA , LOW);
  
    pinMode(motorB, OUTPUT);   /// Inicia salidas de motor apagado
  digitalWrite(motorB, LOW);
 
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
  while(!client.available()){
    delay(1);
  }
 
  // Lee la primera línea requerida
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Coincide con la solicitud
 
  int value = HIGH;
  if (request.indexOf("Uno") != -1)  {
    for (int i= 1; i < 10; i++){
    digitalWrite(ledPin, HIGH); 
    delay (500);
    digitalWrite(ledPin, LOW);
    delay (500);
    }
    Serial.println(request);
    Serial.println("si");
    value =HIGH;
  }

    int value2 = HIGH;
  if (request.indexOf("Dos") != -1)  {
     motorderecha();
    delay (1000);
    motordeterner();
    delay(1000);
    Serial.println(request);
    Serial.println("si");
    value2 =HIGH;
  }

    int value3 = HIGH;
  if (request.indexOf("Tres") != -1)  {
    motorizquierda();
    delay(1000);
    motordeterner();
    delay(1000);
    Serial.println(request);
    Serial.println("si");
    value3 =HIGH;
  }
}

void motorderecha(){
  Serial.println("Girar  derecha");
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
  }

  void motorizquierda(){
  Serial.println("Girar  Izquierda");
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, HIGH);
  }

  void motordeterner(){
   Serial.println("Motores Detenidos");
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
    }
