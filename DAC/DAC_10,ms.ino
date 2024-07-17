
void setup() {
  //Serial.begin(9600);
}

void loop() { 
  for(int i=0; i<256; i++){
    dacWrite(25,i);
    delayMicroseconds(5000.0 / 128.0); //10/256
  }
}




