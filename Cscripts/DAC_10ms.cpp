#include "DAC_10ms.h"
#include <Arduino.h>

void dac() {
    for (int i = 0; i < 256; i++) {
        dacWrite(25, i);
        delayMicroseconds(5000.0 / 128.0);
    }
}
