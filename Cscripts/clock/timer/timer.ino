void performMeasurement() {
    uint64_t start_time = micros();
    double error = 0.94;
    const double delay_time = 5000.0 / 128.0;
    delayMicroseconds(delay_time);

    uint64_t end_time = micros();

    uint64_t elapsed_time = end_time - start_time;
    Serial.println(elapsed_time - delay_time);
}


void setup() {
    Serial.begin(115200);

    while (!Serial) {
        delay(10);
    }
}

void loop() {
    // 重複測量
    performMeasurement();
    delay(100); 
}
