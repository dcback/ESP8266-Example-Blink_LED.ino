// nodeMCU GPIO Read
// ESP8266 : D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 D10
// GPIO    : 16  5  4  0  2 14 12 13 15  3   1 

void setup() {
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop() {

    // 시리얼 모니터 출력
    Serial.print("D0="); Serial.print("GPIO["); Serial.print(D0, DEC); Serial.print("] ");
    Serial.print("D1="); Serial.print("GPIO["); Serial.print(D1, DEC); Serial.print("] ");
    Serial.print("D2="); Serial.print("GPIO["); Serial.print(D2, DEC); Serial.print("] ");
    Serial.print("D3="); Serial.print("GPIO["); Serial.print(D3, DEC); Serial.print("] ");
    Serial.print("D4="); Serial.print("GPIO["); Serial.print(D4, DEC); Serial.print("] ");
    Serial.print("D5="); Serial.print("GPIO["); Serial.print(D5, DEC); Serial.print("] ");
    Serial.print("D6="); Serial.print("GPIO["); Serial.print(D6, DEC); Serial.print("] ");
    Serial.print("D7="); Serial.print("GPIO["); Serial.print(D7, DEC); Serial.print("] "); 
    Serial.print("D8="); Serial.print("GPIO["); Serial.print(D8, DEC); Serial.print("] ");
    Serial.print("D9="); Serial.print("GPIO["); Serial.print(D9, DEC); Serial.print("] ");
    Serial.print("D10="); Serial.print("GPIO["); Serial.print(D10, DEC); Serial.println("] ");
    delay(1000);    // 1초 지연
}
