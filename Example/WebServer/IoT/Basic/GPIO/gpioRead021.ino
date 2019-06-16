// nodeMCU GPIO Read
// GPIO0 == D3, GPIO2 == D4, GPIO15 == D8

int readVal_D3;     // readVal_D3 정수 변수로 정의
int readVal_D4;     // readVal_D4 정수 변수로 정의
int readVal_D8;     // readVal_D8 정수 변수로 정의

void setup() {
    Serial.begin(115200);    // 시리얼 출력(115200) 사용

    Serial.println();
    Serial.println(">>> GPIO Port Reading");
    delay(1000);    // 1초 지연
}

void loop() {
    readVal_D3 = digitalRead(D3);   // D3 핀 읽기
    readVal_D4 = digitalRead(D4);   // D4 핀 읽기
    readVal_D8 = digitalRead(D8);   // D8 핀 읽기

    // 시리얼 모니터 출력
    Serial.print("D3:"); Serial.print(readVal_D3); Serial.print("  ");     
    Serial.print("D4:"); Serial.print(readVal_D4); Serial.print("  ");   
    Serial.print("D8:"); Serial.println(readVal_D8);    
    Serial.println("----------------");
    delay(1000);    // 1초 지연
}
