// nodeMCU LED Blink
// GPIO2 == D4

// 최초 1회 실행(Power On or RESET)
void setup() {
    pinMode(2, OUTPUT);     // GPIO2핀을 출력으로 정의
}

// 무한 반복 실행(실질적 작동단계)
void loop() {
    digitalWrite(2, HIGH);  // GPIO2(D4) 핀 출력을 HIGH
    delay(1000);            // 1000ms(5초) 지연(유지)
    digitalWrite(2, LOW);   // GPIO2(D4) 핀 출력을 LOW
    delay(1000);            // 1000ms(5초) 지연(유지)
}
