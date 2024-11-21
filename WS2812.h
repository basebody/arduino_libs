#ifndef __WS2812_H_
#define __WS2812_H_

#include "Adafruit_NeoPixel.h"

#include "Arduino.h"

//
// RGB LEDs WS2812
//
#define RGB_FL 0
#define RGB_FR 1
#define RGB_RR 2
#define RGB_RL 3

#define RGB_PIN 23
#define RGB_CNT 4

class WS2812 /*: public Adafruit_NeoPixel*/ {
    public:
        WS2812();
        void setColor(uint8_t rgb[3], uint8_t index);
    private:
        Adafruit_NeoPixel _strip = Adafruit_NeoPixel(RGB_CNT, RGB_PIN, NEO_GRB + NEO_KHZ800);
};

#endif // __WS2812_H_