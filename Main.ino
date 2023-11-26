#include <NewPing.h>

#define TRIGGER_PIN_FRONT 22
#define ECHO_PIN_FRONT 2

#define TRIGGER_PIN_RIGHT 23
#define ECHO_PIN_RIGHT 3

#define TRIGGER_PIN_BACK 24
#define ECHO_PIN_BACK 4

#define TRIGGER_PIN_LEFT 25
#define ECHO_PIN_LEFT 5

#define MOTOR_PIN_FRONT_1 26
#define MOTOR_PIN_FRONT_2 27
#define MOTOR_PIN_FRONT_3 28
#define MOTOR_PIN_FRONT_4 29

#define MOTOR_PIN_RIGHT_1 30
#define MOTOR_PIN_RIGHT_2 31
#define MOTOR_PIN_RIGHT_3 32
#define MOTOR_PIN_RIGHT_4 33

#define MOTOR_PIN_BACK_1 34
#define MOTOR_PIN_BACK_2 35
#define MOTOR_PIN_BACK_3 36
#define MOTOR_PIN_BACK_4 37

#define MOTOR_PIN_LEFT_1 38
#define MOTOR_PIN_LEFT_2 39
#define MOTOR_PIN_LEFT_3 40
#define MOTOR_PIN_LEFT_4 41

NewPing sonarFront(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT);
NewPing sonarRight(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT);
NewPing sonarBack(TRIGGER_PIN_BACK, ECHO_PIN_BACK);
NewPing sonarLeft(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT);

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR_PIN_FRONT_1, OUTPUT);
  pinMode(MOTOR_PIN_FRONT_2, OUTPUT);
  pinMode(MOTOR_PIN_FRONT_3, OUTPUT);
  pinMode(MOTOR_PIN_FRONT_4, OUTPUT);

  pinMode(MOTOR_PIN_RIGHT_1, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_2, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_3, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_4, OUTPUT);

  pinMode(MOTOR_PIN_BACK_1, OUTPUT);
  pinMode(MOTOR_PIN_BACK_2, OUTPUT);
  pinMode(MOTOR_PIN_BACK_3, OUTPUT);
  pinMode(MOTOR_PIN_BACK_4, OUTPUT);

  pinMode(MOTOR_PIN_LEFT_1, OUTPUT);
  pinMode(MOTOR_PIN_LEFT_2, OUTPUT);
  pinMode(MOTOR_PIN_LEFT_3, OUTPUT);
  pinMode(MOTOR_PIN_LEFT_4, OUTPUT);
}

void loop() {
  int frontDistance = sonarFront.ping_cm();
  int rightDistance = sonarRight.ping_cm();
  int backDistance = sonarBack.ping_cm();
  int leftDistance = sonarLeft.ping_cm();

  // Front sensor feedback
  if (frontDistance < 50) {
    analogWrite(MOTOR_PIN_FRONT_1, map(frontDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_FRONT_2, map(frontDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_FRONT_3, map(frontDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_FRONT_4, map(frontDistance, 0, 50, 255, 0));
  } else {
    // Turn off motors if no obstacle is detected
    digitalWrite(MOTOR_PIN_FRONT_1, LOW);
    digitalWrite(MOTOR_PIN_FRONT_2, LOW);
    digitalWrite(MOTOR_PIN_FRONT_3, LOW);
    digitalWrite(MOTOR_PIN_FRONT_4, LOW);
  }

  // Right sensor feedback
  if (rightDistance < 50) {
    analogWrite(MOTOR_PIN_RIGHT_1, map(rightDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_RIGHT_2, map(rightDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_RIGHT_3, map(rightDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_RIGHT_4, map(rightDistance, 0, 50, 255, 0));
  } else {
    // Turn off motors if no obstacle is detected
    digitalWrite(MOTOR_PIN_RIGHT_1, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_2, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_3, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_4, LOW);
  }

  // Back sensor feedback
  if (backDistance < 50) {
    analogWrite(MOTOR_PIN_BACK_1, map(backDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_BACK_2, map(backDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_BACK_3, map(backDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_BACK_4, map(backDistance, 0, 50, 255, 0));
  } else {
    // Turn off motors if no obstacle is detected
    digitalWrite(MOTOR_PIN_BACK_1, LOW);
    digitalWrite(MOTOR_PIN_BACK_2, LOW);
    digitalWrite(MOTOR_PIN_BACK_3, LOW);
    digitalWrite(MOTOR_PIN_BACK_4, LOW);
  }

  // Left sensor feedback
  if (leftDistance < 50) {
    analogWrite(MOTOR_PIN_LEFT_1, map(leftDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_LEFT_2, map(leftDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_LEFT_3, map(leftDistance, 0, 50, 255, 0));
    analogWrite(MOTOR_PIN_LEFT_4, map(leftDistance, 0, 50, 255, 0));
  } else {
    // Turn off motors if no obstacle is detected
    digitalWrite(MOTOR_PIN_LEFT_1, LOW);
    digitalWrite(MOTOR_PIN_LEFT_2, LOW);
    digitalWrite(MOTOR_PIN_LEFT_3, LOW);
    digitalWrite(MOTOR_PIN_LEFT_4, LOW);
  }

  delay(100); // Adjust the delay according to your needs
}
