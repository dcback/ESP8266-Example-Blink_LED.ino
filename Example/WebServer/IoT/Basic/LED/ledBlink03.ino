// nodeMCU LED Blink
// GPIO2 == D4

int ledPin D4    // D4핀을 ledPin으로 정의(== #define ledPin D4)

void setup() {
    pinMode(ledPin, OUTPUT);    // D4핀을 출력으로 정의
}

void loop() {
    digitalWrite(ledPin, HIGH); // GPIO2(D4) 핀 출력을 HIGH
    delay(500);                 // 500ms(0.5초) 지연(유지)
    digitalWrite(ledPin, LOW);  // GPIO2(D4) 핀 출력을 LOW
    delay(500);                 // 500ms(0.5초) 지연(유지)
}
