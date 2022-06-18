int pot;
int val;
int rpm_arriba;
int rpm_abajo;
int speedarriba;
int speedabajo;

const int potpin = A0;
const int izq = 6;
const int der = 7;
const int pwm = 3; 
const int ledizq =  9;
const int ledder = 8;

void setup() 
{
  Serial.begin (9600);
  Serial.println ("Inicio");
  pinMode (potpin, INPUT);
  pinMode (izq, OUTPUT);
  pinMode (der, OUTPUT);
  pinMode (pwm, OUTPUT);
  pinMode (ledder, OUTPUT);
  pinMode (ledizq, OUTPUT);
  delay (1000);
}

void loop() 
{
 pot = analogRead (potpin);
 val = map (pot, 0, 1023, 0, 255);

    if(val>132)
    {
   rpm_arriba = (val - 132)*2.07;
   speedarriba=map(rpm_arriba, 0, 254, 0, 100);
   digitalWrite(der, HIGH);
   digitalWrite(izq, LOW);
   analogWrite(pwm, rpm_arriba);
   digitalWrite(ledizq, LOW);
    digitalWrite(ledder, HIGH);
   Serial.print("La velocidad por arriba es de:  ");
   Serial.print(speedarriba);
   Serial.println("%");
    }
  
    else if(val < 123)
    {
    rpm_abajo = (123 - val)*2.07;
    speedabajo = map(rpm_abajo, 0, 254, 0, 100);
    digitalWrite(der, LOW);
    digitalWrite(izq, HIGH);
    analogWrite(pwm, rpm_abajo);
    digitalWrite(ledizq, HIGH);
    digitalWrite(ledder, LOW);
    Serial.print("La velocidad por abajo es de:  ");
    Serial.print(speedabajo);
    Serial.println("%");
    }
  
   else
    {
    digitalWrite(der, LOW);
    digitalWrite(izq, LOW);
    digitalWrite(pwm, 0);
    digitalWrite(ledder, LOW);
    digitalWrite(ledizq, LOW);
    Serial.println("Motor detenido");
    }

}
