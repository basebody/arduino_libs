#ifndef __TEMPERATURE_H_
#define __TEMPERATURE_H_

#include "Arduino.h"

class Temperature {
    public:
        Temperature(uint8_t pin) {_pin = pin;};
        float readTemperatureC();
        float readTemperatureF();
    private:
        uint8_t _pin;
        float _temperatureC;
};


#endif //__TEMPERATURE_H_