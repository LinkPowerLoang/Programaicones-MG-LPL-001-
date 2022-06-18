// C++ code
int potenciometro = A0;
int TMP = A1;

void setup(){
  Serial.begin(9600);
  pinMode(potenciometro, INPUT);
  pinMode(TMP, INPUT);
}

void loop(){
  Serial.print("Potenciometro =   ");
  Serial.println(analogRead(potenciometro));
  Serial.print("TPM =    ");
  Serial.println(analogRead(TMP));
  Serial.println("   ");
    delay(500); 
}
