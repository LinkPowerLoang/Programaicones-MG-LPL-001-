int sensorInclinacion = 3;
int led = 13;
int sonido = 12;
int valor = 0;

void setup()
{
  pinMode (led, OUTPUT);
  pinMode (sensorInclinacion, INPUT);
  pinMode (sonido, OUTPUT);
}

void loop()
{
  valor = digitalRead (sensorInclinacion);
  
  if (valor == LOW)
  {
    digitalWrite (led, 1);
    tone (sonido, 510, 200);
    delay (1000);
  }
  else 
  {
    digitalWrite (led, 0);
    digitalWrite (sonido, 0);
  }
}
