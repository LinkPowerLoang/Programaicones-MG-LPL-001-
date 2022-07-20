#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Familia_G-Ch";
const char* password = "FamiliK.13";
String messageData;

const char* mqtt_server="broker.mqttdashboard.com";

WiFiClient esp32;
PubSubClient client(esp32);

long lastMsg = 0;
long lastMsg2 = 0;
char msg [50];

char data_Temperatura_C_MG [10]="";
char data_Humedad_H_MG [10]="";

#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
int dhtpin = 23;
DHT HT (dhtpin, Type);
float humidity;
float tempC;
float tempF;

// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

//RGB
int rojo = 15;
int azul = 2;
int verde = 4;

void config_wifi(){
  //Conectando se a una red wifi
Serial.print ("Conectandose a la red ");
Serial.println (ssid);
WiFi.begin (ssid, password);
while (WiFi. status () !=WL_CONNECTED) {
delay (500);
Serial.print (",");
}
Serial.println ("") ;
Serial.print ("ESP32 conectado, su IP es: ");
Serial.println (WiFi. localIP());
}

void callback(String topic, byte* message, unsigned int length){
Serial.print ("Mensaje que llega del topic: ");
Serial.print (topic);
Serial.print (". Message: ");
//String message Data:
for (int i =0; i<length; i++) {
Serial.print ( (char) message [i]);
messageData += (char) message [i];
}
Serial.println();
}

void reconnect(){
while (!client.connected()){
Serial.print ("Iniciando conexión con Broker . . ");
String clienteId = "ESP32";
if (client.connect (clienteId.c_str())){
Serial.println ("Conectado ");
client.subscribe ("esp32iot");
}
else{
Serial. print ("Failed, rc=") ;
Serial.print (client .state());
Serial.println (" esperando 3 segundo ");
delay (3000);
}
}
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  HT. begin();
  config_wifi();
  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
  
}
  
void loop() {
  if(!client.connected()){
    reconnect();
  }
  
// Sensor Humedad, temperaturas en ºC y  ºF
      
      humidity = HT.readHumidity();
      tempC = HT.readTemperature();
      tempF = HT.readTemperature(true);
      Serial.print("Humedad: ");
      Serial.println(humidity);
      Serial.print("Temperatura en ºC: ");
      Serial.println(tempC);
      Serial.print("Temperatura en ºF: ");
      Serial.println(tempF);
      Serial.println("");
      delay(100);
sprintf(data_Temperatura_C_MG,"%3.2f", tempC);
client.publish("/Temperatura_Aguilas_MG", data_Temperatura_C_MG);
sprintf(data_Humedad_H_MG,"%3.2f", humidity);
client.publish("/Humedad_Aguilas_MG", data_Humedad_H_MG);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TemC = ");
  lcd.setCursor(7,0);
  lcd.print(tempC);
  lcd.setCursor(0,1);
  lcd.print("Hum  = ");
  lcd.setCursor(7,1);
  lcd.print(humidity);

  if (tempC<25){
    digitalWrite(azul, HIGH);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    } 
    
    if (tempC>25){
    digitalWrite(azul, LOW);
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    } 
    
   if (tempC>30){
    digitalWrite(azul, LOW);
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    } 
}
