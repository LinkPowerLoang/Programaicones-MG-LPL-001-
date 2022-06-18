/*Garcia Choy, Cristian Mateo  6to Electrónica-Roosevelt- 
Proyecto Segunda Unidad 
Robotica 
*/
//Motores Temperatura
#include <Stepper.h>
#define STEPS 200 
Stepper stepper(STEPS, 13, 11, 12, 10);
int motor_1_A = 9;
int motor_1_B = 8;

//Sesor Temperatura
int SensorTem = A0; 
int ValorTempMedido; 
int ValorTempConvertido;  

//Motor y servomotor
 #include <Servo.h>
Servo servo;

int motor_2_A = 7;
int motor_2_B = 6;

//Sesnores LDR, Sensor Distancia y Sensor PIR 
int sensorLDR = A1;
int valor = 0;

int sensorPir = 3;
int datoPir;

#define triggerEmisor A2
#define echoReceptor A3
int distancia;

// Bombilla y Buzzer 
int Bombilla = 4;
int Buzzer = 2;  

void setup() {
  Serial.begin(9600);
  
  stepper.setSpeed(100);
  pinMode(motor_1_A, OUTPUT);
  pinMode(motor_1_B, OUTPUT);
  
  servo.attach(5);
  pinMode(motor_2_A, OUTPUT);
  pinMode(motor_2_B, OUTPUT);

  pinMode(sensorLDR, INPUT);
  pinMode (sensorPir, INPUT);

  pinMode(triggerEmisor, OUTPUT);
  pinMode(echoReceptor, INPUT);

  pinMode(Bombilla, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
 LDR();
 Ultrasonico ();
 PIR ();
  if (valor < 500){
    if ((distancia < 100)||(datoPir==HIGH) ){
    on_Bombilla_buzzer();
    }   
    else{
    off_Bombilla_buzzer();
    }
  }

if (valor > 501){
    off_Bombilla_buzzer();
    }   
}

void motores (){
  stepper.step(200);
  digitalWrite(motor_1_A, HIGH);
  digitalWrite(motor_1_B, LOW);
  delay(500);
  stepper.step(-200);
  digitalWrite(motor_1_A, LOW);
  digitalWrite(motor_1_B, LOW);
  delay(500);
  }

void sensor_temperatura(){
   ValorTempMedido = analogRead(SensorTem);
  Serial.println((String)"Valor medido en entrada analogica: " + ValorTempMedido);
  ValorTempConvertido = map(ValorTempMedido,100,300,0,100);
  Serial.println((String)"Valor medido en entrada analogica: " + ValorTempConvertido); 
  delay(500);
    }

void on_servomotor_y_ventilado(){
      servo.write(180); 
      digitalWrite(motor_2_A, HIGH);
      digitalWrite(motor_2_B, LOW);
      delay(180);
      } 

void off_servomotor_y_ventilado(){
      servo.write(0); 
      digitalWrite(motor_2_A, LOW);
      digitalWrite(motor_2_B, LOW);
      } 

 void LDR (){
  valor = analogRead(sensorLDR);
  Serial.print("Valor del Sensor LDR: ");
  Serial.println(valor);
  }

  void PIR (){
    datoPir = digitalRead(sensorPir);
    Serial.print("Valor del Sensor PIR: ");
    Serial.println(datoPir);
    }
    
void Ultrasonico (){
  digitalWrite(triggerEmisor, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerEmisor, LOW);
  delayMicroseconds(10);
  distancia=pulseIn(echoReceptor,HIGH);
  distancia=distancia/52;
  Serial.print("EL VALOR DE LA DISTANCIA ES DE= ");
  Serial.print(distancia);
  Serial.println(" cm  ");
  delay(100);
      }

 void on_Bombilla_buzzer(){
  digitalWrite(Bombilla, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(100);
  }

  void off_Bombilla_buzzer(){
  digitalWrite(Bombilla, LOW);
  digitalWrite(Buzzer, LOW);
  delay(100);
  }
