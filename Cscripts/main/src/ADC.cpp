#include "../include/ADC.h"
#include <Arduino.h>

int readADC(int pin) {
    return analogRead(pin);
}
