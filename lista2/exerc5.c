/*05) Desenvolva um sistema de porta automática que use um sensor de proximidade
  para detectar a aproximação de uma pessoa e acione um motor para abrir a porta.
*/


#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
int pinoPIR = 13;
int val = 0;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(pinoPIR, INPUT);
}

void loop() {
  val = digitalRead(pinoPIR);
  if (val == 1) {
    Serial.println("Abrindo porta");
    myStepper.step(stepsPerRevolution);
    delay(5000);
    Serial.println("Fechando porta");
    myStepper.step(-stepsPerRevolution);
    delay(1000); 
  }
  else {
    Serial.println("Porta fechada");
    delay(1000);
  }
}
