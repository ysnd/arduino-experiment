#include <Stepper.h>

const int stepPerRevolution = 2048;

Stepper myStepper = Stepper(stepPerRevolution,8,10,9,11);

void setup() {
  

}

void loop() {
  myStepper.setSpeed(5);
  myStepper.step(stepPerRevolution);
  delay(1000);

  myStepper.setSpeed(12);
  myStepper.step(-stepPerRevolution);
  delay(1000);

}
