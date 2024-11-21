#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "Arduino.h"

//
//  MOTORS
//
#define MOTOR_LEFT_IN1 47
#define MOTOR_LEFT_IN2 48
#define MOTOR_LEFT_PWM 46

#define MOTOR_RIGHT_IN1 43
#define MOTOR_RIGHT_IN2 42
#define MOTOR_RIGHT_PWM 44

#define MOTORS_ENABLE 49

class Motor {
public:
  Motor();
  void enable(bool en = true);
  void moveForward(uint8_t speed);
  void moveBackward(uint8_t speed);
  void moveLeft(uint8_t speed);
  void moveRight(uint8_t speed);
  void stop();

private:
  uint8_t _motorDiff = 0;
};

#endif  // __MOTOR_H_