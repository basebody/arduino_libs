#include "Sonar.h"

int Sonar::readCm() {
    delay(50);
    return _sonar.ping_cm();
}

int Sonar::readIn() {
    delay(50);
    return _sonar.ping_in();
} 