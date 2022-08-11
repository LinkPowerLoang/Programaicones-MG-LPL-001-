//NeoPixel
#include <Adafruit_NeoPixel.h>//Adafruit Neopixel library 
#define PIN 32//Pin de los NeoPixel
#define NUMPIXELS 1//Cuanto NeoPixel estan conectados
Adafruit_NeoPixel pixels (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);//definicion de objeto
int brillo = 25;//Intensidad de la NeoPixel

//Definision de los pines del Dip Swicht
#define DS1 27 //Dip Swicht #1
#define DS2 14 //Dip Swicht #2
int estadoDS1 = 0;//Variable para leer estado del dip swicht
int estadoDS2 = 0;//Variable para leer estado del dip swicht

//Botton Start
#define Start 35//Definicion de Pin de inicio
int StartOld; //Variable para leer estado del dip swicht
int StartNew; //Variable para leer estado del dip swicht
int ON; //Variable para leer estado del dip swicht

//Pines en tarjeta GEC 2021 para sensores Sharp GP2Y0E02A
// Definir pines para Sensores Sharp GP2Y0E02A
#define sensorDistanciaJ1 33// Sharp J1 -> io33
#define sensorDistanciaJ2 25// Sharp J2 -> io25
#define sensorDistanciaJ3 26// Sharp J3 -> io26
int estadoSensorDistanciaJ1 = 0;//Variables para leer estado del sensor de distancia J1
int estadoSensorDistanciaJ2 = 0;//Variables para leer estado del sensor de distancia J2
int estadoSensorDistanciaJ3 = 0;//Variables para leer estado del sensor de distancia J3
int Valor1;
int Valor2;
int Valor3;

//Pines en tarjeta GEC para sensor  Sensores QRE1113
//Definir pines para Sensores QRE1113
#define sensorQRE1 36 //QRE1
#define sensorQRE2 39 //QRE2
#define sensorQRE3 34 //QRE3
int estadoSensorQRE1 = 0;//Variables para leer estado de color de QRE1 
int estadoSensorQRE2 = 0;//Variables para leer estado de color de QRE2
int estadoSensorQRE3 = 0;//Variables para leer estado de color de QRE3

//Motores
#include <GEC_DRV8833.h>// Libreria del Motor 
GEC_DRV8833 gecDriver = GEC_DRV8833();//Crear instancia de nuestra libreria
const int inputA1 = 13;//Pines para motores en kit GEC 2021
const int inputA2 = 15;//Pines para motores en kit GEC 2021
const int inputB1 = 2;//Pines para motores en kit GEC 2021
const int inputB2 = 4;//Pines para motores en kit GEC 2021
int velocidad1 = 165;// Definir velocidad del motor
int velocidad2 = 165;// Definir velocidad del motor
int tiempoPruebas = 750;// Definir retraso de tiempo 

//Servomotor 
int servo = 5;

void setup() {
  // Activador del monitor serial
  Serial.begin(115200);
  
  //Definir configuracion de pines de entrada y salida 
  pinMode(DS1, INPUT);
  pinMode(DS2, INPUT);
  pinMode(Start, INPUT);
  pinMode(sensorDistanciaJ1, INPUT);
  pinMode(sensorDistanciaJ2, INPUT);
  pinMode(sensorDistanciaJ3, INPUT);
  pinMode(sensorQRE1, INPUT);
  pinMode(sensorQRE2, INPUT);
  pinMode(sensorQRE3, INPUT);
  pinMode(servo, OUTPUT);

  pixels.begin (); //Inicia el objeto a utilizar
  pixels.setBrightness(brillo);  //Asignar el brillo

  // Desactivar lo colores del NeoPixel
  pixels.clear();//Limper el color del NeoPixel 
  pixels.show();//Mostrar el color
  delay (1000);

  //Vincular pines con motor de GEC 2021 KIT board
 vincularMotores();
 
 servomotor0();
}

void loop() {
  //Loop para leer y desplegar el estado de Start
  StartNew = digitalRead(Start);
  Serial.print("Valor en Start = ");
  Serial.println(StartNew);  
   delay(80);  
   
    
    //configuracion de start
  if((StartNew == LOW) && (StartOld == HIGH)){ 
    ON = 1 -ON;
    delay(5000);//tiempo de inicio & apagado
    }
    StartOld=StartNew;
    
  if(ON == 1){
     //Loop para leer y desplegar el estado de DS1
  estadoDS1 = digitalRead(DS1);
  Serial.print("Valor en DS1 = ");
  Serial.println(estadoDS1);
//Loop para leer y desplegar el estado de DS2
  estadoDS2 = digitalRead(DS2);
  Serial.print("Valor en DS2 = ");
  Serial.println(estadoDS2);

  //Loop para leer y desplegar el estado del sensor Sharp GP2Y0E02A J1
  Valor1 = analogRead(sensorDistanciaJ1);
  estadoSensorDistanciaJ1=((Valor1)-2823.6)/(-66.957);
  Serial.print("Valor en sensor distancia J1 =");
  Serial.println(estadoSensorDistanciaJ1);
  
  //Loop para leer y desplegar el estado del sensor Sharp GP2Y0E02A J2
   Valor2 = analogRead(sensorDistanciaJ2);
  estadoSensorDistanciaJ2=((Valor2)-2823.6)/(-66.957);
  Serial.print("Valor en sensor distanciaJ2 =");
  Serial.println(estadoSensorDistanciaJ2);
  
  //Loop para leer y desplegar el estado del sensor Sharp GP2Y0E02A J3
   Valor3 = analogRead(sensorDistanciaJ3);
  estadoSensorDistanciaJ3=((Valor3)-2823.6)/(-66.957);
  Serial.print("Valor en sensor distanciaJ3 =");
  Serial.println(estadoSensorDistanciaJ3);
  
  //Loop para leer y desplegar el estado de color de QRE1 
  estadoSensorQRE1 = analogRead(sensorQRE1);
  Serial.print("Valor en sensor QRE1 =");
  Serial.println(estadoSensorQRE1);
  //Loop para leer y desplegar el estado de color de QRE2 
  estadoSensorQRE2 = analogRead(sensorQRE2);
  Serial.print("Valor en sensor QRE2 =");
  Serial.println(estadoSensorQRE2);
  //Loop para leer y desplegar el estado de color de QRE3 
  estadoSensorQRE3 = analogRead(sensorQRE3);
  Serial.print("Valor en sensor QRE3 =");
  Serial.println(estadoSensorQRE3);  
  
  //==============>(DS0)<==============
    if((estadoDS1 == 1) && (estadoDS2 == 1)){
      pixels.clear();
      pixels.show();
     servomotor0(); 
  gecDriver.motor1StopAt();
  gecDriver.motor2StopAt();

    }
    
    //==============>(DS1)<==============
   if((estadoDS1 == 0) && (estadoDS2 == 1)){
      encenderRojo();//NeoPixel encendido del color rojo
      servomotor90();//Servomotor en 90 grados
      
      //=============(Sensores De Distancia)====================    
        if(estadoSensorDistanciaJ1<= 15){
  girarRoverDer();//Rover girando
  stopGiro2(); //Rover detenido
  delay(100);
        }
        
                if(estadoSensorDistanciaJ3<= 15){
  girarRoverIzq(); //Rover girando
  stopGiro();//Rover detenido
  delay(100);
        }
        
         if(estadoSensorDistanciaJ2<= 15){
  motoresAdelante();//Moviendo rover hacia adelante
  stopMotoresAdelante(); //Rover detenido
  delay(100);
        }
        if(estadoSensorDistanciaJ2>= 16){
  girarRover360();//Moviendo rover hacia adelante
  stopGiro(); //Rover detenido
  delay(100);
        }
        
 
        //=====================(Sensores De Linea)===================
        if(estadoSensorQRE1<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }

        if(estadoSensorQRE2<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }
   
        if(estadoSensorQRE3<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }

    }
    
    //==============>(DS2)<==============
   if((estadoDS1 == 1) && (estadoDS2 == 0)){
      encenderAmarillo();
      servomotor90();
      
   //=============(Sensores De Distancia)====================    
        if(estadoSensorDistanciaJ1<= 15){
  girarRoverDer();//Rover girando
  stopGiro2(); //Rover detenido
  delay(100);
        }

                if(estadoSensorDistanciaJ3<= 15){
  girarRoverIzq(); //Rover girando
  stopGiro();//Rover detenido
  delay(100);
        }
        
         if(estadoSensorDistanciaJ2<= 15){
  motoresAdelante();//Moviendo rover hacia adelante
  stopMotoresAdelante(); //Rover detenido
  delay(100);
        }
        if(estadoSensorDistanciaJ2>= 16){
  girarRover360();//Moviendo rover hacia adelante
  stopGiro(); //Rover detenido
  delay(100);
        }
 
        //=====================(Sensores De Linea)===================
        if(estadoSensorQRE1<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }

        if(estadoSensorQRE2<=1100){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }
   
        if(estadoSensorQRE3<=800){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }
     }
        
    //==============>(DS3)<==============
   if((estadoDS1 == 0) && (estadoDS2 == 0)){
      encendercerCeleste();
      servomotor90();
      
     //=============(Sensores De Distancia)====================    
        if(estadoSensorDistanciaJ1<= 15){
  girarRoverDer();//Rover girando
  stopGiro2(); //Rover detenido
  delay(100);
        }
        
                if(estadoSensorDistanciaJ3<= 15){
  girarRoverIzq(); //Rover girando
  stopGiro();//Rover detenido
  delay(100);
        }
        
         if(estadoSensorDistanciaJ2<= 15){
  motoresAdelante();//Moviendo rover hacia adelante
  stopMotoresAdelante(); //Rover detenido
  delay(100);
        }
        if(estadoSensorDistanciaJ2>= 16){
  girarRover360();//Moviendo rover hacia adelante
  stopGiro(); //Rover detenido
  delay(100);
        }   
 
        //=====================(Sensores De Linea)===================
        if(estadoSensorQRE1<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }

        if(estadoSensorQRE2<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }
   
        if(estadoSensorQRE3<=1000){
  motoresAtras();//Rover atras
  stopMotoresAtras(); //Rover detenido
  delay(100);
        }
    }
  }
  else{
      pixels.clear();
      pixels.show();
      servomotor0();
      gecDriver.motor1StopAt();
      gecDriver.motor2StopAt();
    }
  }
  
  //Colores para el NeoPixel
void encenderRojo(){
pixels.setPixelColor (0, pixels.Color(150,0,0));//Mostrar el color rojo 
pixels.show();//Mostrar el color
  }

void encenderAmarillo(){
pixels.setPixelColor (0, pixels.Color(249,209,10));//Mostrar el color Amarillo
pixels.show();//Mostrar el color 
  }

void encendercerCeleste(){
pixels.setPixelColor (0, pixels.Color(5,255,243));//Mostrar el color Celeste
pixels.show();//Mostrar el color 
  }

void servomotor0(){
   // ============>(0º)<===============
  for (int Hz =0; Hz < 50 ; Hz++){ //repetimos la instrucion 50 veces
    digitalWrite(servo, HIGH);
    delayMicroseconds(400); // llevamos 0º
    digitalWrite(servo, LOW);
    delay(19);
    }
  } 

  void servomotor90(){
    // ============>(90º)<===============
  for (int Hz =0; Hz < 50 ; Hz++){ //repetimos la instrucion 50 veces
    digitalWrite(servo, HIGH);
    delayMicroseconds(1500); // llevamos 90º
    digitalWrite(servo, LOW);
    delay(19);
     }
    }
    
void vincularMotores(){
  // Vincular pines con motores de GEC 2021 KIT Board
  gecDriver.vincularMotor1(inputA1, inputA2);
  gecDriver.vincularMotor2(inputB1, inputB2);
  Serial.println("Motores listos para acción!");
}

void motoresAdelante(){
  Serial.println("Motores hacia adelante");
  gecDriver.motor1Adelante(velocidad1);
  gecDriver.motor2Adelante(velocidad2);
  delay(100);
}
void motoresAdelante2(){
  Serial.println("Motores hacia adelante");
  gecDriver.motor1Adelante(velocidad1);
  gecDriver.motor2Adelante(velocidad2);
  delay(100);
}

void motoresAtras(){
  Serial.println("Motores hacia atrás");
  gecDriver.motor1Atras(velocidad1);
  gecDriver.motor2Atras(velocidad2);
  delay(100);
}

void stopMotoresAdelante(){
  Serial.println("Detener motores");
  gecDriver.motor1StopAd();
  gecDriver.motor2StopAd();
  delay(100);
}

void stopMotoresAtras(){
  Serial.println("Detener motores");
  gecDriver.motor1StopAt();
  gecDriver.motor2StopAt();
  delay(100);
}

void girarRoverIzq(){
  Serial.println("Girando rover izquierda");
  gecDriver.motor1Adelante(velocidad1);
  gecDriver.motor2Atras(velocidad2);
  delay(100);
}

void girarRoverDer(){  
  Serial.println("Girar rover derecha");
  gecDriver.motor1Atras(velocidad1);
  gecDriver.motor2Adelante(velocidad2);
  delay(100);
}

void girarRover360(){
  Serial.println("Girando rover 360");
  gecDriver.motor1Adelante(velocidad1);
  gecDriver.motor2Atras(velocidad2);
  delay(100);
}

void stopGiro(){
  Serial.println("Detener motores");
  gecDriver.motor1StopAd();
  gecDriver.motor2StopAt();
  delay(100);
}

void stopGiro2(){
  Serial.println("Deteniedo motores");
  gecDriver.motor1StopAt();
  gecDriver.motor2StopAd();
}
