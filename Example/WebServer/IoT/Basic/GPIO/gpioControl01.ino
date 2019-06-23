// ctrlPin(D3) LOW/HIGH 제어 -> Serial Monitor

int ctrlPin = D3;     // ctrlPin을 D3로 정의
int ledPin  = D4;     // cledPin을 D4로 정의
int ctrlValue;        // ctrlValue를 정수변수로 정의  

void setup() {
    Serial.begin(115200);       // 시리얼 출력(115200) 사용
    pinMode(ctrlPin, OUTPUT);   // ctrlPin을 출력으로 정의
    pinMode(ledPin, OUTPUT);    // ctrlPin을 출력으로 정의  
}

void loop() {
    digitalWrite(ctrlPin, LOW);         // ctrlPin에 LOW 출력 
    ctrlValue = digitalRead(ctrlPin);   // ctrlPin값 ctrlValue에 입력
    digitalWrite(ledPin, ctrlValue);    // ledPin에 ctrlPin출력   
    delay(1000);                        // 1초 지연
    Serial.print("ctrlPin Value:"); Serial.println(ctrlValue);
    
    digitalWrite(ctrlPin, HIGH);        // ctrlPin에 HIGH 출력 
    ctrlValue = digitalRead(ctrlPin);   // ctrlPin값 ctrlValue에 입력
    digitalWrite(ledPin, ctrlValue);    // ledPin에 ctrlPin출력    
    delay(1000);                        // 1초 지연    
    Serial.print("ctrlPin Value:"); Serial.println(ctrlValue);
}
