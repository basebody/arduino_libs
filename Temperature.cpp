#include "Temperature.h"

float Temperature::readTemperatureC() {
    _temperatureC = (analogRead(_pin) * (5.0 / 1023.0)) * 100.0;
    return  _temperatureC;
}

float Temperature::readTemperatureF() {
    return (_temperatureC * 9 / 5) + 32;
}