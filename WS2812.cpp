#include "WS2812.h"

WS2812::WS2812() {
    _strip.begin();
    _strip.show();
}

void WS2812::setColor(uint8_t rgb[3], uint8_t index) {
    if (index <= RGB_CNT) {
        _strip.setPixelColor(index, _strip.Color(rgb[0], rgb[1], rgb[2]));
    }
    _strip.show();
}