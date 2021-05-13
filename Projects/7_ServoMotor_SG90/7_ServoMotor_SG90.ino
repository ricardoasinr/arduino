#include <Servo.h>
Servo servo1;


int VALORPOT;
int ANGULO;

void setup() {
  servo1.attach(8);
  Serial.begin(9600);
}

void loop() {

  VALORPOT = analogRead(A3);
  Serial.println(VALORPOT); //min 5, max 1017
  ANGULO= map(VALORPOT, 10, 1021, 0, 180);
  servo1.write(ANGULO);
  
  delay(20);
  
  
}
