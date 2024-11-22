#include "Temperature.h"

float Temperature::readTemperatureC() {
    delay(50);
    _temperatureC = (analogRead(_pin) * (5.0 / 1023.0)) * 100.0;
    return  _temperatureC;
}

float Temperature::readTemperatureF() {
    delay(50);
    _temperatureC = (analogRead(_pin) * (5.0 / 1023.0)) * 100.0;
    return (_temperatureC * 9 / 5) + 32;
}