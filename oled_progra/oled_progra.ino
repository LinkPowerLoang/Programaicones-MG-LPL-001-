#define _DEBUG_
#include <WiFi.h> 
#include <PubSubClient.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

const char* ssid = "ARRIS-5C92-2.4G-ext";
const char* password = "2PM7H7603581";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];

int value = 0;

void setup_wifi() {
  delay(10);
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

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String content = "";
  for (int i = 0; i < length; i++) {
    content.concat((char)payload[i]);
      
  }
Serial.println("variable: ");
Serial.println(content);

long variable1;
variable1 = content.toInt();
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 32);
    
 if (variable1 > 30) {
    digitalWrite(12, HIGH);
    digitalWrite(14, LOW);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 15);
    display.println("temp: > 30"); 
    display.display();
 }

else {
  if (variable1 < 20){
    digitalWrite(12, LOW);
    digitalWrite(14, LOW); 
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 15);
    display.println("temp: < 20");
    display.display();
  }
  
    if (variable1 <= 15){
    digitalWrite(12, LOW);
    digitalWrite(14, HIGH); 
    display.clearDisplay();
    display.setTextSize(2); 
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 15);
    display.println("temp: <= 15");
    display.display();
  }
}
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish("liceo/bosques/hector1", "hello world");
      client.subscribe("liceo/roosevelt/chaj");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
 #ifdef _DEBUG_
  Serial.begin(115200);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
  
#endif
  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef _DEBUG_
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
  pinMode(12, OUTPUT);  
  pinMode(14, OUTPUT);   
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
   client.loop();
   client.subscribe("liceo/roosvelt/hector2");
}
