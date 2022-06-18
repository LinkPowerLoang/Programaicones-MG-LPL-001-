int led_1 = 2;
int led_2 = 3;
int led_3 = 4;

long randomNumber;

void setup()
{
  Serial.begin(9600);
   Serial.println("Iniciar led a lo random");
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

 randomSeed(analogRead(A0));
}

void loop() 
{
 randomNumber =  random(2,5);

 Serial.print("El numero random es = ");
 Serial.println("randomNumber");

 digitalWrite(randomNumber, HIGH);
 delay(100);
 digitalWrite(randomNumber, LOW);

}
