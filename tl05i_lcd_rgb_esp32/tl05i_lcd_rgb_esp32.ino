// LCD
#include <LiquidCrystal_I2C.h>

// sensor tl05i
#include <Wire.h> 
#include "Adafruit_SHT31.h"
Adafruit_SHT31 sensor = Adafruit_SHT31();

//LCD
LiquidCrystal_I2C lcd (0x27, 16, 2);

//RGB
int rojo = 15;
int azul = 2;
int verde = 4;


void setup() {
  Serial.begin(115200);
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  
  if(sensor.begin(0x44)){
    Serial.println("Sensor encontrado");
  }else{
    Serial.println("Sensor NO encontrado");
    while(1){
      delay(10);
    }
  }
}

void loop() {
  float temp = sensor.readTemperature();
  float hume = sensor.readHumidity();

  //isnan -> is not a number?
  if(isnan(temp)){
    Serial.println("Error al obtener temperatura");
  }else{
    Serial.print("Temperatura *C = ");
    Serial.println(temp);
  }

  //! isnan -> is not not a number? -> is a number?
  if(!isnan(hume)){
    Serial.print("Humedad % = ");
    Serial.println(hume);
  }else{
    Serial.println("Error al obtener humedad");
  }
  Serial.println();
  delay(10);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tem=");
  lcd.setCursor(5,0);
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("Hum= ");
  lcd.setCursor(5,1);
  lcd.print(hume);

  if (temp<25){
    digitalWrite(azul, HIGH);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    } 
    
    if (temp>25){
    digitalWrite(azul, LOW);
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    } 
    
   if (temp>30){
    digitalWrite(azul, LOW);
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    } 
}
