/*
My first variable
Fade in and fade out a LED with the press of a button.
*/

int led = 3;
int button = 10;
int x = 1;
boolean currentState = LOW;
boolean lastState = LOW;
boolean ledState = LOW;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(button);
  if(currentState == HIGH && lastState == LOW) {
    delay(1);
    
    if (ledState == HIGH) {
      Serial.println("OFF");
      for(int i = 255; i >= 0; i=i-x) {
        analogWrite(led, i);
        delay(2);
      }
      ledState=LOW;
    }
    else {
      Serial.println("ON");
      for(int i = 0; i <= 255; i=i+x) {
        analogWrite(led, i);
        delay(3);
      }
      ledState=HIGH;
    }
  }
  lastState = currentState;
}

