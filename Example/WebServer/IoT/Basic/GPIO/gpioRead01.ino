// nodeMCU GPIO Read
// GPIO0 == D3(Flash SW), GPIO2 == D4(LED)

int swPin  = D3;        // D3핀을 swPin으로 정의
int ledPin = D4;        // D4핀을 ledPin으로 정의     
int swState = LOW;      // 초기 버튼 상태 = 0 

void setup() {
    pinMode(ledPin, OUTPUT);    // D4핀을 출력으로 정의
    pinMode(swPin, INPUT);      // D3핀을 입력으로 정의
}

void loop() {
    swState = digitalRead(swPin);   // 입력 핀(D3)으로부터 읽기
    digitalWrite(ledPin, swState);  // 읽은 값(swState)으로 LED출력
}
