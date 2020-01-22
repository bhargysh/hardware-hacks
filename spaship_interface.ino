int switchState = 0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW) { //if button is not pressed
    digitalWrite(3, HIGH); //turn on green LED
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW); //turn off green LED
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
  }

}
