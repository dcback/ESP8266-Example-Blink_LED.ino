#define ledPin      D4
#define csPin       D8
#define resetPin    D0

#include <SPI.h>
#include <LoRa.h>

void setup() {
    Serial.begin(115200);
    while (!Serial);

    pinMode(ledPin, OUTPUT);

    LoRa.setPins(csPin, resetPin);  // CS, RST, (IRQ) Pin Set

    Serial.println("LoRa Receiver");

    if (!LoRa.begin(915E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}

bool ledStatus = HIGH;

void loop() {
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        // received a packet
        Serial.print("Received packet '");

        // read packet
        while (LoRa.available()) {
            Serial.print((char)LoRa.read());
        }

        // print RSSI of packet
        Serial.print("' with RSSI ");
        Serial.println(LoRa.packetRssi());

        ledStatus = !ledStatus;
        digitalWrite(ledPin, ledStatus);
    }
}

void onReceive(int packetSize) {
    if (packetSize == 0) return;          // if there's no packet, return

    // read packet header bytes:
    byte incomingLength = LoRa.read();    // incoming msg length

    String incoming = "";

    while (LoRa.available()) {
        incoming += (char)LoRa.read();
    }

    if (incomingLength != incoming.length()) {   // check length for error
        Serial.println("error: message length does not match length");
        return;                             // skip rest of function
    }
    Serial.println("Message: " + incoming);
    Serial.println("RSSI: " + String(LoRa.packetRssi()));
}
