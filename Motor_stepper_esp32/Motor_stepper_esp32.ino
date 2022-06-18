#include <WiFi.h> // Libreria para placa ESP32
#include <SPI.h>
const char* ssid = "Familia_G-Ch";
const char* password = "FamiliK.13";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,50);
String readString; 

#include <Stepper.h> 
double stepsPerRevolution = 2048;
double stepsPerRevolution1 = 1070;    
                                                                //IN1,IN3,IN2,IN4
Stepper myStepper(stepsPerRevolution, 21, 18, 19, 5);  // Pin inversion to make the library work

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 myStepper.setSpeed(10);  
 
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

  if (request.indexOf("Abrir") != -1)  {
     Serial.println("0 a 180 "); 
    myStepper.step(stepsPerRevolution1);  
    delay(1000); 
  }

  if (request.indexOf("Cerrar") != -1)  {
   Serial.println("180 a 0");  
   myStepper.step(-stepsPerRevolution1); 
   delay(1000); 
  }

  if (request.indexOf("Total_mas") != -1)  {
    Serial.println("0 a 360"); 
    myStepper.step(stepsPerRevolution);  
    delay(1000); 
  }

  if (request.indexOf("Total_menos") != -1)  {
   Serial.println("360 a 0");  
   myStepper.step(-stepsPerRevolution); 
   delay(1000); 
  }
}
