#define __DEBUG__
#include <WiFi.h> // Import ESP32 WiFi library
#include <PubSubClient.h>// Import PubSubClient library to initialize MQTT protocol
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Update these with values suitable for your network.
// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

const char* ssid = "J4+";//use your ssid
const char* password = "lavidaesuna";//use your password
const char* mqtt_server = "test.mosquitto.org";

//pines a usar
int LED_verde = 23;
int Motor_a = 13;
int Motor_b = 12;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
// Check for Message received on define topic for MQTT Broker
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String content = "";
  for (int i = 0; i < length; i++) {
    content.concat((char)payload[i]);
      
  }
Serial.println("la variable es:");
Serial.println(content);
long variable1;
variable1 = content.toInt();
 
  if (variable1 > 30) {
    digitalWrite(LED_verde, HIGH);
    digitalWrite(Motor_a, HIGH);
    digitalWrite(Motor_b, LOW);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(12, 20);
    display.print("Temperatura:  ");
    display.println(variable1);  
    display.display();
    } 
    
   if (variable1 > 16 && variable1 < 20) {
    digitalWrite(LED_verde, LOW);
    digitalWrite(Motor_a, LOW);
    digitalWrite(Motor_b, LOW);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(12, 20);
    display.print("Temepratura:  "); 
    display.println(variable1); 
    display.display();
  }

   if (variable1 < 15) {
    digitalWrite(LED_verde, HIGH);
    digitalWrite(Motor_a, LOW);
    digitalWrite(Motor_b, HIGH);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(12, 20);
    display.print("Temepratura:  "); 
    display.println(variable1); 
    display.display();
  }  
  }

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("liceo/roosvelt/mateo1", "hello world");
      // ... and resubscribe
      client.subscribe("liceo/roosvelt/mateo2");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}



void setup() {
 #ifdef __DEBUG__
  Serial.begin(115200);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
  
#endif

  // Iniciar pantalla OLED en la dirección 0x3C
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
  pinMode(LED_verde, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
 pinMode(Motor_a, OUTPUT); 
 pinMode(Motor_b, OUTPUT); 
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

   client.loop();
   client.subscribe("liceo/roosvelt/mateo2");
  
}
