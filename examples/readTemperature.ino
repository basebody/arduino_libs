#include "Libs.h"

Temperature temp(/*Your pin*/);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println(temp.readTemperatureC() + " C°" + "\n" + temp.readTemperatureF() + " F°");
}