#include "../include/DAC_10ms.h"
#include <Arduino.h>
#include <Arduino.h>
#include "include/DAC_10ms.h"
#include "include/ADC.h"

const int adcPin = 34;
const int dacPin = 25;

void dac(int pin) {
  for(int i=0;i<256;i++){
        double t0 = t;
        t = micros();
        dacWrite(pin, i);
        Serial.println(i);
        delayMicroseconds(5000.0/128.0);
    }
}
