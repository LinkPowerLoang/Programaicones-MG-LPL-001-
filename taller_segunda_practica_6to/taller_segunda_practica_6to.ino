#include <WiFi.h>
#include <SPI.h>
const char* ssid = "Familia_G-Ch";
const char* password = "FamiliK.13";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 50);
String readString;

int Poten = 35; 
int valor ; 
String respuesta ="0";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  
   pinMode(Poten, INPUT);
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
    
    if (req.indexOf("estado") != -1){
      valor = analogRead(Poten);
      respuesta = String (valor);
      Serial.println(respuesta);
      delay(10);
      }
     client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println(respuesta);
      Serial.print("Cliente desconectado: ");
      Serial.println(client.remoteIP());
      client.flush();
      client.stop();
      
}
