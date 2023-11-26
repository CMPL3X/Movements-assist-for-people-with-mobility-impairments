// Code, to test if all the motors work correctly
const int motorPins[] = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
const int numMotors = 16;

void setup() {
  Serial.begin(9600);

  // Set all motor pins as OUTPUT
  for (int i = 0; i < numMotors; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numMotors; i++) {
    digitalWrite(motorPins[i], HIGH);  // Turn on the current motor
    Serial.print("Turned ON Motor ");
    Serial.println(i + 1);

    delay(1000);  // Wait for 1 second

    digitalWrite(motorPins[i], LOW);  // Turn off the current motor
    Serial.print("Turned OFF Motor ");
    Serial.println(i + 1);

    delay(500);  // Wait for 0.5 seconds before moving to the next motor
  }
}