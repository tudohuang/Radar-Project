const int dacPin = 25;
const int numSamples = 512; 
uint8_t data[numSamples]; 
const unsigned long targetTime = 10000; // 目標時間 10 毫秒 (10000 微秒)

void setup() {
    pinMode(dacPin, OUTPUT);
    Serial.begin(9600);

    // 預先生成 0-255 的數據
    for (int i = 0; i < numSamples; i++) {
        data[i] = (i * 255) / (numSamples - 1);
    }
}

void loop() {
    unsigned long start = micros(); // 開始計時

    for (int i = 0; i < numSamples; i++) {
        dacWrite(dacPin, data[i]);
    }

    unsigned long end = micros(); // 結束計時
    unsigned long duration = end - start;

    if (duration < targetTime) {
        while ((micros() - start) < targetTime) {
        }
    }

}