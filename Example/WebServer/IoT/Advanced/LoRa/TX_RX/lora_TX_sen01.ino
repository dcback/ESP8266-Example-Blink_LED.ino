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
#define csPin       D8
#define resetPin    D0

bool ledStatus = HIGH;
int counter = 0;
char buf[100];

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(500);

    pinMode(ledPin, OUTPUT);

    LoRa.setPins(csPin, resetPin);  // CS, RST, (IRQ) Pin Set

    Serial.println("LoRa Sender");

    if (!LoRa.begin(915E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }

    if (!bme.begin(0x76)) {         // BME280(I2C addr=0x76) begin
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
}

void loop() {
    Serial.print("Sending packet: ");
    Serial.println(counter);

    Monitoring();

    // send packet
    LoRa.beginPacket();
    LoRa.print(buf);
    LoRa.endPacket();

    counter++;

    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus);
    delay(1000);
}

char tempVal_str[10];
char humiVal_str[10];
char pressVal_str[10];
char altiVal_str[10];

void Monitoring() {
    int readVal_A0 = analogRead(A0);
    float tempVal = bme.readTemperature();    // 온도 값 출력
    float humiVal = bme.readHumidity();       // 습도 값 출력
    float pressVal = bme.readPressure() / 100.0F; // 기압 값 출력
    float altiVal = bme.readAltitude(SEALEVELPRESSURE_HPA);   // 고도 값 출력

    dtostrf(tempVal, 2, 2, tempVal_str);    // float to string 
    dtostrf(humiVal, 2, 2, humiVal_str);    // float to string
    dtostrf(pressVal, 3, 2, pressVal_str);  // float to string
    dtostrf(altiVal, 3, 2, altiVal_str);    // float to string

    sprintf(buf, ">>>[%d %s %s %s %s]", readVal_A0, tempVal_str, humiVal_str, pressVal_str, altiVal_str);
    Serial.println(buf);
}
