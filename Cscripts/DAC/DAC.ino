#include <Arduino.h>

const int dacPin = 25;
const int adcPin = 34;  // ADC 引腳，ESP32 上 ADC 引腳範圍 32-39
const double delayt = 5000.0 / 128.0;  // 每個樣本的延遲時間（微秒）

#define Num_Samples  256
byte SawtoothWaveTable[Num_Samples];

void setup() {
    Serial.begin(115200);

    // 生成鋸齒波數據表
    /*
    for (int i = 0; i < Num_Samples; i++) {
        SawtoothWaveTable[i] = (byte)(255.0 * i / Num_Samples);
    }
    */
}

void loop() {
    // 使用預先生成的波形數據輸出到 DAC
    for(int i = 0; i < 256; i++){
        dacWrite(dacPin, i);
        delayMicroseconds(delayt);
    }
}
