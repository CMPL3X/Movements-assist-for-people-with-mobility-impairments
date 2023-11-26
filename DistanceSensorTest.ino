#include <NewPing.h>

#define TRIGGER_PIN_FRONT 22
#define ECHO_PIN_FRONT 22

#define TRIGGER_PIN_RIGHT 23
#define ECHO_PIN_RIGHT 23

#define TRIGGER_PIN_BACK 24
#define ECHO_PIN_BACK 24

#define TRIGGER_PIN_LEFT 25
#define ECHO_PIN_LEFT 25

NewPing sonarFront(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT);
NewPing sonarRight(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT);
NewPing sonarBack(TRIGGER_PIN_BACK, ECHO_PIN_BACK);
NewPing sonarLeft(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int frontDistance = sonarFront.ping_cm();
  int rightDistance = sonarRight.ping_cm();
  int backDistance = sonarBack.ping_cm();
  int leftDistance = sonarLeft.ping_cm();

  Serial.print("Front Distance: ");
  Serial.print(frontDistance);
  Serial.println(" cm");

  Serial.print("Right Distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  Serial.print("Back Distance: ");
  Serial.print(backDistance);
  Serial.println(" cm");

  Serial.print("Left Distance: ");
  Serial.print(leftDistance);
  Serial.println(" cm");

  delay(1000);  // Adjust the delay according to your needs
}
