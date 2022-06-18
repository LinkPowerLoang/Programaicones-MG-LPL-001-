#include <WiFi.h>
#include <SPI.h>
const char* ssid = "Familia_G-Ch";
const char* password = "FamiliK.13";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 50);
String readString;

//LDR
int sensor_LDR = 35;
int valor = 0;

//Sensor agua
int SENSOR;

//Sensor de temperatura y humedada 
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
int dhtpin = 23;
DHT HT (dhtpin, Type);
float humidity;
float tempC;
float tempF;

//motor de agua y ventilador 
int motor_A_1 = 15;
int motor_B_1 = 2;

int motor_C_1 = 22;
int motor_D_1 = 21;

// Luces (UV y LED)
int LED_UV = 27;
int LED = 14;  


WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  HT. begin();

  pinMode(motor_A_1, OUTPUT);
  pinMode(motor_B_1, OUTPUT);
  pinMode(motor_C_1, OUTPUT);
  pinMode(motor_D_1, OUTPUT);
  pinMode(LED_UV, OUTPUT);
  pinMode(LED, OUTPUT);
  
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
  WiFiClient client = server.available();
  if(!client){
    return;
    }
    Serial.print("Nuevo cliente:   ");
    Serial.println(client.remoteIP());
    String req = client.readStringUntil('\r');
    Serial.print(req);


    // Sensores
      if (req.indexOf("Sensores") != -1){
    //Sesnor LDR
      valor = analogRead(sensor_LDR);
      Serial.print("Valor del Sensor LDR: ");
      Serial.println(valor);
      delay(1000);
      //Sensor agua
      SENSOR = analogRead(34);
      Serial.print("Cantida de agua en la tierra: ");
      Serial.println(SENSOR);
      delay(1000);
      // Sensor Humedad, temperaturas en ºC y  ºF
      humidity = HT.readHumidity();
      tempC = HT.readTemperature();
      tempF = HT.readTemperature(true);
      Serial.print("Huemedad: ");
      Serial.println(humidity);
      Serial.print("Temperatura en ºC: ");
      Serial.println(tempC);
      Serial.print("Temperatura en ºF: ");
      Serial.println(tempF);
      delay(1000);
      }
      
   //Mensajes para la app
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.print(humidity);
      client.print(",");
      client.print(tempF);
      client.print(",");
      client.print(tempC);
      client.print(",");
      client.print(SENSOR);
      client.print(",");
      client.print(valor);
      
      Serial.println("Cliente desconectado: ");
      Serial.println(client.remoteIP());
      client.flush();
      client.stop();

      // Motor de agua  encendido Agua 
      if (req.indexOf("A_A") != -1){
      digitalWrite(motor_A_1, HIGH);
      digitalWrite(motor_B_1, LOW);
      }
      // Motor de agua apagado  Agua 
      if (req.indexOf("B_B") != -1){
      digitalWrite(motor_A_1, LOW);
      digitalWrite(motor_B_1, LOW);     
      }
      
    // LED para encender luminacion
      if (req.indexOf("C_C") != -1){
     digitalWrite(LED, HIGH);
      }
      // LED para apagar luminacion
      if (req.indexOf("D_D") != -1){
     digitalWrite(LED, LOW);
      }
      
      // LED para encender UV
      if (req.indexOf("A1") != -1){
     digitalWrite(LED_UV, HIGH);
      }
      // LED para apagar UV
      if (req.indexOf("B1") != -1){
     digitalWrite(LED_UV, LOW);
      }

      // Motor de ventilador
      if (req.indexOf("C1") != -1){
      digitalWrite(motor_C_1, HIGH);
      digitalWrite(motor_D_1, LOW);
      }
      // Motor de ventilador
      if (req.indexOf("D1") != -1){
      digitalWrite(motor_C_1, LOW);
      digitalWrite(motor_D_1, LOW);     
      }
}
