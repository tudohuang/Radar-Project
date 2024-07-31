#include <Arduino.h>
#include "include/DAC_10ms.h"
#include "include/ADC.h"

const int adcPin = 34;
const int dacPin = 25;

void dacTask(void *pvParameters) {
    while (1) {
        dac(dacPin);
    }
}

void adcTask(void *pvParameters) {
    const TickType_t xFrequency = 1000 / portTICK_PERIOD_MS;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    while (1) {
        int value = readADC(adcPin);
        Serial.println(value);
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void setup() {
    Serial.begin(9600);
    Serial.println("Setup start");
    xTaskCreate(dacTask,"DAC Task",2048,NULL,1,NULL);
    xTaskCreate(adcTask,"ADC Task",2048,NULL,1,NULL);
    pinMode(adcPin, INPUT); 
}

void loop() {
}
