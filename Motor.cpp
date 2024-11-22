#include "Motor.h"

Motor::Motor(uint8_t motorRightForward, uint8_t motorRightBackward, uint8_t motorRightPWM, uint8_t motorLeftForward, uint8_t motorLeftBackward, uint8_t motorLeftPWM) {
  uint8_t _motorRightForward = motorRightForward;
  uint8_t _motorRightBackward = motorRightBackward;
  uint8_t _motorRightPWM = motorRightPWM;
  uint8_t _motorLeftForward = motorLeftForward;
  uint8_t _motorLeftBackward = motorLeftBackward;
  uint8_t _motorLeftPWM = motorLeftPWM;

  pinMode(MOTOR_LEFT_IN1, OUTPUT);
  pinMode(MOTOR_LEFT_IN2, OUTPUT);
  pinMode(MOTOR_RIGHT_IN1, OUTPUT);
  pinMode(MOTOR_RIGHT_IN2, OUTPUT);
  pinMode(MOTORS_ENABLE, OUTPUT);
}

void Motor::enable(bool en) {
  digitalWrite(MOTORS_ENABLE, en);
}

void Motor::moveForward(uint8_t speed) {
  analogWrite(_motorLeftPWM, speed);
  analogWrite(_motorRightPWM, speed);

  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, HIGH);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

void Motor::moveBackward(uint8_t speed) {
  analogWrite(_motorLeftPWM, speed);
  analogWrite(_motorRightPWM, speed);

  digitalWrite(MOTOR_LEFT_IN1, HIGH);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, HIGH);
}

void Motor::moveLeft(uint8_t speed) {
  analogWrite(_motorLeftPWM, 0);
  analogWrite(_motorRightPWM, speed);

  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

void Motor::moveRight(uint8_t speed) {
  analogWrite(_motorLeftPWM, speed);
  analogWrite(_motorRightPWM, 0);

  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, HIGH);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

void Motor::stop(){
  analogWrite(_motorLeftPWM, 0);
  analogWrite(_motorRightPWM, 0);

  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}