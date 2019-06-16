// nodeMCU GPIO analogRead(A0)

int readVal_A0;     // readVal_A0 정수 변수로 정의

void setup() {
    Serial.begin(115200);    // 시리얼 출력(115200) 사용

    Serial.println();
    Serial.println(">>> A0 Port Reading");
    delay(1000);    // 1초 지연
}

void loop() {
    readVal_A0 = analogRead(A0);   // A0 핀 읽기

    // 시리얼 모니터 출력
    Serial.print("A0 readValue:"); Serial.println(readVal_A0);
    delay(1000);    // 1초 지연
}
