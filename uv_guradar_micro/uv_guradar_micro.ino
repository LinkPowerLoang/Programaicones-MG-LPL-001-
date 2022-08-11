#include <SPI.h>    
#include <SD.h>    
 
#define SSpin 4 

File archivo;     

void setup() {
  Serial.begin(9600);   

  Serial.println("Inicializando tarjeta ...");  
  if (!SD.begin(SSpin)) {   
    Serial.println("fallo en inicializacion !");
    return;      
  }
  Serial.println("inicializacion correcta");  
  archivo = SD.open("datos.txt", FILE_WRITE); 

  if (archivo) {  
    for (int i=1; i < 31; i++){    
      
  float sensorVoltage; 
  float sensorValue;
  float uVindex;
  
  sensorValue = analogRead(A4);
  sensorVoltage = sensorValue/1024*5;
  uVindex = sensorVoltage/0.1;

  archivo.print(i);
  archivo.print(",");
  archivo.print("sensor reading = ");
  archivo.print(sensorValue);
  archivo.print(",");
 archivo.print("sensor voltage = ");
  archivo.print(sensorVoltage);
  archivo.print(" V");
  archivo.print(",");
  archivo.print("UV index = ");
  archivo.println(uVindex);


  Serial.print(i);  
  Serial.print(",");
  Serial.print("sensor reading = ");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.print(" V");
  Serial.print(",");
  Serial.print("UV index = ");
  Serial.println(uVindex);
 
  delay(1000);   
      }
    archivo.close();       
    Serial.println("escritura correcta"); 
  } else {
    Serial.println("error en apertura de datos.txt"); 
  }
}

void loop() {       

}
