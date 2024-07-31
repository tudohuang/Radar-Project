#include <Arduino.h>

const int dacPin = 25;  // DAC 引腳
const int adcPin = 34;  // ADC 引腳
const double delayt = 5000.0 / 128.0;  // 每個樣本的延遲時間（微秒）

#define Num_Samples  256
byte SawtoothWaveTable[Num_Samples];
double startTime, endTime;  // 記錄時間
int adcValue;

void setup() {
    Serial.begin(115200);

    // 生成鋸齒波數據表
    for (int i = 0; i < Num_Samples; i++) {
        SawtoothWaveTable[i] = (byte)(255.0 * i / Num_Samples);
    }
}

void loop() {
    for (int i = 0; i < Num_Samples; i++) {
        // 記錄開始時間
        startTime = micros();
        
        // 使用 DAC 輸出信號
        dacWrite(dacPin, i);
        delayMicroseconds(delayt);

        adcValue = analogRead(adcPin);
        // 記錄結束時間
        endTime = (double)micros();
        // 讀取 ADC 值

        // 計算延遲時間並輸出到串口
        double delayTime = endTime - startTime;
        Serial.println(delayTime);

    }
}
