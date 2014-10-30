/*
Control the servo rotation with a potentiometer.
*/

#include <Servo.h>
Servo servo;
int pot = 0;
int a;

void setup() {
  servo.attach(10);
}

void loop() {
  a = analogRead(pot);
  a = map(a, 0, 1023, 0, 179);
  servo.write(a);
  delay(10);
}
