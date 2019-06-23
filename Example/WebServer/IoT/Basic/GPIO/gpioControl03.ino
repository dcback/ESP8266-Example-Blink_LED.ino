// buzzPin(D3) DO RE MI tone/noTone function use

int buzzPin  = D3;  // buzzPin을 D3로 정의
int num = 8;
int tones[] = {261, 294, 329, 349, 392, 440, 493, 523}; //도 레 미..주파수 정의

void setup() {
}

void loop() {
    for (int i = 0; i < num; i++) {
        tone(buzzPin, tones[i]);    // tone(pin, frequency)
        delay(1000);
    }
    noTone(buzzPin);    // noTone(pin)
    delay(1000);
}
