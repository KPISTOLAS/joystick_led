int xPin = A0;
int yPin = A1;
int buttonPin = 7;

int upLED = 10;
int downLED = 6;
int leftLED = 11;
int rightLED = 5;

void setup() {

  pinMode(upLED, OUTPUT);
  pinMode(downLED, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
  boolean button = digitalRead(buttonPin);

  int upPWM = map(yVal, 511, 0, 0, 255);
  int downPWM = map(yVal, 511, 1023, 0, 255);
  int leftPWM = map(xVal, 511, 0, 0, 255);
  int rightPWM = map(xVal, 511, 1023, 0, 255);

  if (yVal <= 511) {
    analogWrite(upLED, upPWM);
  }

  if (yVal >= 511) {
    analogWrite(downLED, downPWM);
  }

  if (xVal <= 511) {
    analogWrite(leftLED, leftPWM);
  }

  if (xVal >= 511) {
    analogWrite(rightLED, rightPWM);
  }

  if (button == LOW) {
    digitalWrite(upLED, HIGH);
    digitalWrite(downLED, HIGH);
    digitalWrite(leftLED, HIGH);
    digitalWrite(rightLED, HIGH);
  }
}