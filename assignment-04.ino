/*
Push force gauge
The stronger the force applied, the slower the LED blinks. The goal is to reach the blue LED color.
*/

int red = 11;
int green = 10;
int blue = 9;
int fsr = 0;
int t = 4096; //control the speed of blink

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  fsr = analogRead(0);
  Serial.println(fsr);
  delay(1);
 
  if(fsr >= 0 && fsr < 40) {
    B();
  }
  
  else if(fsr > 40 && fsr < 500) {
    O();
    delay(t/fsr);
    G();
    delay(t/fsr);
  }
  
  else if(fsr > 500 && fsr <= 1023) {
    R();
    delay(500);
    O();
    delay(500);
  }
}

void R() { //red
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void G() { //green
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void B() { //blue
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 0);
}

void O() { //led off
  analogWrite(green, 255);
  analogWrite(red, 255);
  analogWrite(blue, 255);
}
