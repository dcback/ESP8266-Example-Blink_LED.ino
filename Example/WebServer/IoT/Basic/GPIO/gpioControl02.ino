// buzzPin(D3) tone/noTone function use

int buzzPin  = D3;  // buzzPin을 D3로 정의

void setup() {
}

void loop() {
    tone(buzzPin, 4000);    // tone(pin, frequency)
    delay(1000);
    
    noTone(buzzPin);        // noTone(pin)
    delay(1000);
}
