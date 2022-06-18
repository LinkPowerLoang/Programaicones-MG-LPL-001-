int ventilador = 23;
// int motor_agua =
// int motor_calor =
 
void setup() {
Serial.begin (9600);
pinMode(ventilador, OUTPUT);
}

void loop() {
  //Ventilador 
    if (Serial.available()> 0){
    int Dato = Serial.read();
       if (Dato=='V'){
          digitalWrite(ventilador, HIGH);
          delay(1000);
          }else if (Dato=='A'){
              digitalWrite(ventilador, LOW);
              delay(1000);  
             }
    }
    
   //motor de agua  
/*     if (Serial.available()> 0){
      int Dato = Serial.read();
       if (Dato=='C'){
          digitalWrite(motor_agua, HIGH);
          delay(1000);
          }else if (Dato=='P'){
              digitalWrite(motor_agua, LOW);
              delay(1000);  
             }
    }
   */
       //motor de calor 
  /*  if (Serial.available()> 0){
      int Dato = Serial.read();
       if (Dato=='Q'){
          digitalWrite(motor_calor, HIGH);
          delay(1000);
          }else if (Dato=='W'){
              digitalWrite(motor_calor, LOW);
              delay(1000);  
             }
    }
    */
}
