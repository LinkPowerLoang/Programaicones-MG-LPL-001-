#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "THOR17";
const char* password = "Hola1234";
String messageData;

const char* mqtt_server="test.mosquitto.org";

WiFiClient esp32;
PubSubClient client(esp32);

long lastMsg = 0;
long lastMsg2 = 0;
char msg [50];

char data_gas_mq2 [10]="";

int pindig1_digital=32;
int pindig2_Led=33;
int pinana_analog=34;

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
  pinMode(pindig1_digital,INPUT);
  pinMode(pindig2_Led,OUTPUT);
  config_wifi();
  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
  
}
  
void loop() {
  if(!client.connected()){
    reconnect();
  }
   
  int val_digital;
 int val_analog;
 val_digital= digitalRead(pindig1_digital);
 val_analog= analogRead(pinana_analog);

 Serial.print("Sensor de Gas analogico =  ");
 Serial.println(val_analog);
 Serial.print("Sensor de Gas digital =  ");
 Serial.println(val_digital);

sprintf(data_gas_mq2,"%1u", val_analog);
client.publish("practica1/sexto", data_gas_mq2);

 if(val_analog>1000)
 {
  Serial.println("Gas");
  digitalWrite(pindig2_Led,HIGH);
  Serial.println("");
  delay(1500);
 }

 else
 {
  Serial.println("No hay Gas");
  digitalWrite(pindig2_Led,LOW);
  Serial.println("");
  delay(1500);
 }

}
