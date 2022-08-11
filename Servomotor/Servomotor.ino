int servo = 5;

void setup (){
  pinMode(servo, OUTPUT);
   Serial.begin(115200);
}
void loop (){
  
 // ============>(0º)<===============
  for (int Hz =0; Hz < 50 ; Hz++){ //repetimos la instrucion 50 veces
    digitalWrite(servo, HIGH);
    delayMicroseconds(400); // llevamos 0º
    digitalWrite(servo, LOW);
    delay(19);
    }
    Serial.println("0º");
    delay(2000);
  
// ============>(90º)<===============
  for (int Hz =0; Hz < 50 ; Hz++){ //repetimos la instrucion 50 veces
    digitalWrite(servo, HIGH);
    delayMicroseconds(1500); // llevamos 90º
    digitalWrite(servo, LOW);
    delay(19);
    }
    Serial.println("90º");
    delay(2000);
}
