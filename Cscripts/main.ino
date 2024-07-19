#include "DAC_10ms.h"
#include "ADC.h"

const int adcPin = 34;
const int dacPin = 25;
unsigned long lastADCReadTime = 0;
const unsigned long adcDelay = 1000;

void setup() {
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    dac(dacPin);
    
    unsigned long currentTime = millis();
    if (currentTime - lastADCReadTime >= adcDelay) {
        int value = readADC(adcPin);
        Serial.println(value);
        lastADCReadTime = currentTime;
    }
}
