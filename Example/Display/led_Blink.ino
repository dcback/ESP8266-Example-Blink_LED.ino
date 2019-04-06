#define ledPin  2   // == D2
unsigned int cnt;
 
void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    
    Serial.println(cnt);
    cnt++;
}
