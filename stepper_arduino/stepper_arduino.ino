#include <Stepper.h>
int stepsPerRevolucion = 2048;
int motSpeed = 10;
Stepper myStepper(stepsPerRevolucion, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(motSpeed);
}

void loop() {
  myStepper.step(stepsPerRevolucion);
}
