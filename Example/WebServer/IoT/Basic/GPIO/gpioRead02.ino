// nodeMCU GPIO Read
// GPIO0 == D3, GPIO2 == D4, GPIO15 == D8

int readVal_0;        // readVal_0 정수 변수로 정의
int readVal_2;        // readVal_2 정수 변수로 정의
int readVal_15;       // readVal_15 정수 변수로 정의

void setup() {
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
    
    Serial.println(">>> GPIO Port Reading");
    delay(1000);    // 1초 지연
}

void loop() {
    readVal_0 = digitalRead(0);     // GPIO0 핀 읽기
    readVal_2 = digitalRead(2);     // GPIO2 핀 읽기
    readVal_15 = digitalRead(15);   // GPIO15 핀 읽기

    // 시리얼 모니터 출력
    Serial.print("GPIO[0]:"); Serial.print(readVal_0); Serial.print("  ");     
    Serial.print("GPIO[2]:"); Serial.print(readVal_2); Serial.print("  ");   
    Serial.print("GPIO[15]:"); Serial.println(readVal_15);    
    Serial.println("--------------------------------");
    delay(1000);    // 1초 지연
}
