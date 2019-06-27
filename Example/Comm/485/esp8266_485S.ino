// nodeMCU_485 Slave
#include <SoftwareSerial.h>

#define SSerialRX        D1     //Serial Receive pin(485_RO)
#define SSerialTX        D2     //Serial Transmit pin(485_DI)
#define SSerialTxControl D3     //RS485 Direction control

#define RS485Transmit   HIGH
#define RS485Receive    LOW
#define pinLed          D4

SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

int byteReceived;
int byteSend;
int ledState = HIGH;

void setup() {
    Serial.begin(9600);
    Serial.println("");
    Serial.println(">>> RS485 Slave receiving");

    pinMode(pinLed, OUTPUT);
    pinMode(SSerialTxControl, OUTPUT);

    digitalWrite(SSerialTxControl, RS485Receive);

    RS485Serial.begin(9600);
}

void loop() {

    while (RS485Serial.available()) {
        byteSend = RS485Serial.read();   // Read the byte
        Serial.print(byteSend);
        Serial.print(" ");
        digitalWrite(pinLed, ledState);  // Show activity
    }
    Serial.println();
    ledState = !ledState;
    delay(1000);
}
