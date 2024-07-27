#include "../include/DAC_10ms.h"
#include <Arduino.h>

void dac(int pin) {
  const double delaySecond = 5000.0/128.0;  
  for(int i=0;i<256;i++){
        dacWrite(pin, i);
        delayMicroseconds(delaySecond);
    }
}
