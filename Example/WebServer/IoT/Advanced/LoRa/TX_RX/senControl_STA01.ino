#include <Wire.h>               // I2C
#include <Adafruit_Sensor.h>    // BME280
#include <Adafruit_BME280.h>    // BME280
#include <LiquidCrystal_I2C.h>  // LCD
#include <SPI.h>                // SPI for LoRa 
#include <LoRa.h>               // LoRa

#define SEALEVELPRESSURE_HPA (1013.25)  // Altitude ref for BME280 
Adafruit_BME280 bme;                    // BME280

LiquidCrystal_I2C lcd(0x27, 16, 2);     // set the LCD address(I2C) to 0x27

#define ledPin      D4
#define buzzPin     D3
#define csPin       D8
#define resetPin    D0

void Init_Receive();    // LoRa setup
void LoRa_Receive();    // LoRa receive
void functions();       // LED, BUZZ/RELAY, A0 Read
void Monitoring();      // Serial monitoring

int readVal_A0;

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(500);

    lcd.begin();        // LCD initialize
    lcd.backlight();    // Backlight on

    lcd.print("ABCDEFGHIJKLMNOP");  // ABCDEFGHIJKLMNOP Print
    lcd.setCursor(0, 1);            // LCD x=0, y=1 point cursor
    lcd.print("QRSTUVWXYZ012345");  // QRSTUVWXYZ012345 Print
    lcd.noDisplay();                // LCD Off
    delay(500);
    lcd.display();                  // LCD On
    delay(500);

    pinMode(ledPin, OUTPUT);

    if (!bme.begin(0x76)) {         // BME280(I2C addr=0x76) begin
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }

    LoRa.setPins(csPin, resetPin);  // CS, RST, (IRQ) Pin Set
    Init_Receive();
}

void loop() {
    LoRa_Receive();
}

// ===========================
// Functions()
// ===========================
void functions() {
    digitalWrite(ledPin, LOW);
    tone(buzzPin, 4000);
    delay(500);
    digitalWrite(buzzPin, HIGH);
    delay(500);

    readVal_A0 = analogRead(A0);
    digitalWrite(ledPin, HIGH);
    noTone(buzzPin);
    digitalWrite(buzzPin, LOW);
    delay(500);
}

void Monitoring() {
    Serial.print("A0 readValue:"); Serial.println(readVal_A0);
    Serial.println("-----------------");
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());    // 온도 값 가져와서 출력
    Serial.println("*C");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());       // 습도 값 가져와서 출력
    Serial.println("%");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F); // 기압 값 가져와서 출력
    Serial.println("hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));   // 고도 값 가져와서 출력
    Serial.println("m");

    Serial.println();
}

void LoRa_Receive() {
    // try to parse packet
    int packetSize = LoRa.parsePacket();    // LoRa data 패킷 분석
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

        functions();    // LoRa data receive loop
        Monitoring();   // LoRa data receive loop
    }
}

void Init_Receive() {
    Serial.println("LoRa Receiver");

    if (!LoRa.begin(915E6)) {       // LoRa begin & check
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}
