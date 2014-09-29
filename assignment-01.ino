/*
My first program
SOS in Morse Code using the onboard LED.
*/

int led = 13; // naming the LED on pin 13

void setup() {
  pinMode(led, OUTPUT); // the LED is the output
}

void loop() {
  S(); // each letter have an specific blink variation
  O();
  S();
  delay(800); // delay to start the loop again
}

void S() {
  dot(); // S in Morse code is three short blinks
  dot();
  dot();
  delay(400); // delay to start the next letter
}

void O() {
  dash(); // O in Morse code is three long blinks
  dash();
  dash();
  delay(400);
}

void dot() { 
  digitalWrite(13, HIGH); 
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}

void dash() {
  digitalWrite(13, HIGH); // 
  delay(600);
  digitalWrite(13, LOW);
  delay(200);
}

