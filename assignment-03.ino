/*
Use of analog input and output
Fade in and fade out three LEDs asymmetrically with the use of a potentiometer.
*/

int pot = 0;
int led1 = 9;
int led2 = 10;
int led3 = 11;

int last = 0;
int value = 0;
int value2 = 0;
int value3 = 0;

int brightness1 = 0;
int brightness2 = 0;
int brightness3 = 0;

void setup() {
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  Serial.print(brightness1);
  Serial.print(brightness2);
  Serial.println(brightness3);
  delay(10);
 
  value = analogRead(pot);
  brightness1 = map(value, 0, 1023, 0, 255);
  
  value2 = constrain(value, 341, 1023);
  brightness2 = map(value2, 341, 1023, 0, 255);
  
  value3 = constrain(value, 683, 1023);
  brightness3 = map(value3, 683, 1023, 0, 255);
  
  if(last < value + 1) {
  analogWrite(led1, brightness1);
  analogWrite(led2, brightness2);
  analogWrite(led3, brightness3);
  }
  
  else {
  analogWrite(led1, brightness3);
  analogWrite(led2, brightness2);
  analogWrite(led3, brightness1);
  }
    
    last = value;
}
