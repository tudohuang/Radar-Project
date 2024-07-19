#include "DAC_10ms.h"
#include <Arduino.h>

void dac(int pin) {
    static unsigned long lastUpdate = 0;
    static int i = 0;
    unsigned long currentTime = millis();
    double deltaSecond = 5000.0/128.0;
    if (currentTime - lastUpdate >= deltaSecond) {
        dacWrite(pin, i);
        i++;
        if (i >= 256) {
            i = 0;
        }
        lastUpdate = currentTime;
    }
}
