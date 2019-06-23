// buzzPin(D3) digitalWrite() use

int buzzPin   = D3;     // buzzPin을 D3로 정의
int delayTime = 1;      // 지연시간(1ms) 변수 할당

void setup() {
    pinMode(buzzPin, OUTPUT);
}

void loop() {
    digitalWrite(buzzPin, HIGH);        // Buzz On HIGH
    delay(delayTime);                   // delayTime 지연
    digitalWrite(buzzPin, LOW);         // Buzz Off LOW
    delay(delayTime);                   // delayTime 지연
}
