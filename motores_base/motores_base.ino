#include <TB6612_ESP32.h>

//MOTOR2
#define BIN1 25
#define BIN2 26
#define PWMB 14

const int offsetB = 1;

Motor ventilador = Motor(BIN1, BIN2, PWMB, offsetB, 0, 5000, 8, 2);

void setup()
{
}

void loop()
{
  forward(ventilador, ventilador, 100);
  delay(2000);
  back(ventilador, ventilador, 100);
  delay(2000);
  brake(ventilador, ventilador);
  delay(2000);
}
