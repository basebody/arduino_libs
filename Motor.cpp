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

  digitalWrite(_motorLeftBackward, LOW);
  digitalWrite(_motorLeftForward, HIGH);
  digitalWrite(_motorRightForward, HIGH);
  digitalWrite(_motorRightBackward, LOW);
}

void Motor::moveBackward(uint8_t speed) {
  analogWrite(_motorLeftPWM, speed);
  analogWrite(_motorRightPWM, speed);

  digitalWrite(_motorLeftBackward, HIGH);
  digitalWrite(_motorLeftForward, LOW);
  digitalWrite(_motorRightForward, LOW);
  digitalWrite(_motorRightBackward, HIGH);
}

void Motor::moveLeft(uint8_t speed) {
  analogWrite(_motorLeftPWM, 0);
  analogWrite(_motorRightPWM, speed);

  digitalWrite(_motorLeftBackward, LOW);
  digitalWrite(_motorLeftForward, LOW);
  digitalWrite(_motorRightForward, HIGH);
  digitalWrite(_motorRightBackward, LOW);
}

void Motor::moveRight(uint8_t speed) {
  analogWrite(_motorLeftPWM, speed);
  analogWrite(_motorRightPWM, 0);

  digitalWrite(_motorLeftBackward, LOW);
  digitalWrite(_motorLeftForward, HIGH);
  digitalWrite(_motorRightForward, LOW);
  digitalWrite(_motorRightBackward, LOW);
}

void Motor::stop(){
  analogWrite(_motorLeftPWM, 0);
  analogWrite(_motorRightPWM, 0);

  digitalWrite(_motorLeftBackward, LOW);
  digitalWrite(_motorLeftForward, LOW);
  digitalWrite(_motorRightForward, LOW);
  digitalWrite(_motorRightBackward, LOW);
}