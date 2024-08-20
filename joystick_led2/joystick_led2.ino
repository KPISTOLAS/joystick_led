#define joyX A0
#define joyY A1
#define joyButton 7

int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 12;

void setup() {
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(joyButton, INPUT_PULLUP); // Assuming the button is active LOW
}

void loop() {
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);
  int buttonState = digitalRead(joyButton); // Declare buttonState here

  // Print the values to the Serial Monitor
  Serial.print(xValue);
  Serial.print("\t");
  Serial.print(yValue);
  Serial.print("\t");
  Serial.println(buttonState);

  // Control LEDs based on joystick input
  if (xValue > 501) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  if (xValue < 501) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }

  if (yValue > 501) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

  if (yValue < 501) {
    digitalWrite(led4, HIGH);
  } else {
    digitalWrite(led4, LOW);
  }

  // Turn on led5 when the joystick button is pressed
  if (buttonState == LOW) { // Assuming the button press pulls the pin LOW
    digitalWrite(led5, HIGH);
  } else {
    digitalWrite(led5, LOW);
  }

  delay(100); // Adding a small delay to make the Serial Monitor output more readable
}