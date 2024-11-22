#ifndef __SONAR_H_
#define __SONAR_H_

#include "Arduino.h"

#include "libs/NewPing/NewPing.h"

//
// Ultrasonic
//
#define SONAR_TRIG 24
#define SONAR_ECHO 25
#define MAX_DISTANCE 200

class Sonar {
    public:
        Sonar(uint8_t echo, uint8_t trig, uint32_t max_distance) {_sonar = NewPing(echo, trig, max_distance);}
        int readCm();
        int readIn();
    private:
        NewPing _sonar;
};


#endif //__SONAR_H_