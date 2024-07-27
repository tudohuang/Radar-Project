const int dacPin = 25;

void setup() {
  Serial.begin(9600);
}

void micr_micr() {
  for(int i = 0; i < 256; i++) {
    unsigned long t0 = micros();
    delayMicroseconds(5 * 1000 / 128);
    unsigned long t = micros();
    double real = (double)(t - t0); 
    double expectedDelay = 5.0 * 1000.0 / 128.0; 
    double error = real - expectedDelay;

    Serial.print("micr_micr: ");
    Serial.println(abs(error), 4);  
  }
}

void micr_milli() {
  for(int i = 0; i < 256; i++) {
    unsigned long t0 = millis();
    delayMicroseconds(5 * 1000 / 128);
    unsigned long t = millis();
    double real = (double)(t - t0) * 1000.0; 
    double expectedDelay = 5.0 * 1000.0 / 128.0;
    double error = real - expectedDelay;

    Serial.print("micr_milli: ");
    Serial.println(abs(error), 4); 
  }
}

void milli_micr() {
  for(int i = 0; i < 256; i++) {
    unsigned long t0 = micros();
    delay(5 / 128);
    unsigned long t = micros();
    double real = (double)(t - t0);
    double expectedDelay = 5.0 * 1000.0 / 128.0;
    double error = real - expectedDelay;

    Serial.print("milli_micr: ");
    Serial.println(abs(error), 4);
  }
}

void milli_milli() {
  for(int i = 0; i < 256; i++) {
    unsigned long t0 = millis();
    delay(5 / 128);
    unsigned long t = millis();
    double real = (double)(t - t0) * 1000.0;
    double expectedDelay = 5.0 * 1000.0 / 128.0;
    double error = real - expectedDelay;

    Serial.print("milli_milli: ");
    Serial.println(abs(error), 4);  
  }
}

void loop() {
  //micr_micr(); 
  //micr_milli();
  //milli_micr();
  milli_milli();
}
