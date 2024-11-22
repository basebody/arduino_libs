#ifndef __WS2812_H_
#define __WS2812_H_

#include "libs/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

#include "Arduino.h"

class WS2812 {
    public:
        WS2812(uint8_t count, uint8_t pin);
        void setColor(uint8_t rgb[3], uint8_t index);
    private:
        Adafruit_NeoPixel _strip;
};

#endif // __WS2812_H_