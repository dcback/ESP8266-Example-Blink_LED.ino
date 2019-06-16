// nodeMCU GPIO analogRead

void setup() {
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop() {

    // 시리얼 모니터 출력
    Serial.print("D0:"); Serial.print(analogRead(D0)); Serial.print(" ");     
    Serial.print("D1:"); Serial.print(analogRead(D1)); Serial.print(" ");
    Serial.print("D2:"); Serial.print(analogRead(D2)); Serial.print(" ");     
    Serial.print("D3:"); Serial.print(analogRead(D3)); Serial.print(" ");
    Serial.print("D4:"); Serial.print(analogRead(D4)); Serial.print(" ");     
    Serial.print("D5:"); Serial.print(analogRead(D5)); Serial.print(" ");
    Serial.print("D6:"); Serial.print(analogRead(D6)); Serial.print(" ");     
    Serial.print("D7:"); Serial.print(analogRead(D7)); Serial.print(" ");
    Serial.print("D8:"); Serial.print(analogRead(D8)); Serial.print(" ");     
    Serial.print("D9:"); Serial.print(analogRead(D9)); Serial.print(" ");   
    Serial.print("D10:"); Serial.print(analogRead(D10)); Serial.println(" ");    

    delay(1000);    // 1초 지연
}
