#include "../include/DAC_10ms.h"
#include <Arduino.h>

void dac(int pin) {
  for(int i=0;i<256;i++){
        dacWrite(pin, i);
        Serial.println(i);
        delayMicroseconds(5000.0/128.0);
    }
}
