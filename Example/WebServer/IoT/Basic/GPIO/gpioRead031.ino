// nodeMCU GPIO digitalRead

void setup() {
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop() {

    // 시리얼 모니터 출력
    Serial.print("D0:"); Serial.print(digitalRead(D0)); Serial.print(" ");     
    Serial.print("D1:"); Serial.print(digitalRead(D1)); Serial.print(" ");
    Serial.print("D2:"); Serial.print(digitalRead(D2)); Serial.print(" ");     
    Serial.print("D3:"); Serial.print(digitalRead(D3)); Serial.print(" ");
    Serial.print("D4:"); Serial.print(digitalRead(D4)); Serial.print(" ");     
    Serial.print("D5:"); Serial.print(digitalRead(D5)); Serial.print(" ");
    Serial.print("D6:"); Serial.print(digitalRead(D6)); Serial.print(" ");     
    Serial.print("D7:"); Serial.print(digitalRead(D7)); Serial.print(" ");
    Serial.print("D8:"); Serial.print(digitalRead(D8)); Serial.print(" ");     
    Serial.print("D9:"); Serial.print(digitalRead(D9)); Serial.print(" ");   
    Serial.print("D10:"); Serial.print(digitalRead(D10)); Serial.println(" ");    

    delay(1000);    // 1초 지연
}
