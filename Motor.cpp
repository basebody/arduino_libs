#include "Motor.h"

Motor::Motor(uint8_t motorRightForward, uint8_t motorRightBackward, uint8_t motorRightPWM, uint8_t motorLeftForward, uint8_t motorLeftBackward, uint8_t motorLeftPWM, uint8_t motorEnable) {
  _motorRightForward = motorRightForward;
  _motorRightBackward = motorRightBackward;
  _motorRightPWM = motorRightPWM;
  _motorLeftForward = motorLeftForward;
  _motorLeftBackward = motorLeftBackward;
  _motorLeftPWM = motorLeftPWM;
  _motorEnable = motorEnable;

  pinMode(_motorLeftBackward, OUTPUT);
  pinMode(_motorLeftForward, OUTPUT);
  pinMode(_motorRightForward, OUTPUT);
  pinMode(_motorRightBackward, OUTPUT);
  pinMode(_motorEnable, OUTPUT);
}

void Motor::enable(bool en) {
  digitalWrite(_motorEnable, en);
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