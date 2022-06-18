#include <IRremote.h>
#define Boton_1 0xFF30CF
#define Boton_2 0xFF18E7
#define Boton_3 0xFF7A85

int IR = 9;
int LEDAZUL = 10;
int LEDROJO = 11;
int LEDVERDE = 12;

IRrecv irrecv(IR);
decode_results codigo;
 


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LEDAZUL, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
}

void loop()
{
 if(irrecv.decode(&codigo))
  {
   Serial.println(codigo.value, HEX);
   if (codigo.value == Boton_1)
   digitalWrite(LEDAZUL, !digitalRead(LEDAZUL));

   if (codigo.value == Boton_2)
   digitalWrite(LEDROJO, !digitalRead(LEDROJO));

   if (codigo.value == Boton_3)
   digitalWrite(LEDVERDE, !digitalRead(LEDVERDE));
   
   irrecv.resume();
  
  }
 delay (100); 
 }
