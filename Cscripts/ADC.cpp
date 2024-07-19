#include "ADC.h"
#include <Arduino.h>

int readADC(int pin) {
    int value = analogRead(pin);
    return value;
}
