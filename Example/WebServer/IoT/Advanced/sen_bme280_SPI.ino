// BME280 SPI Interface ESP8266
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// assign the SPI bus to pins
#define BME_SCK  D1     // SCL
#define BME_MISO D4     // SDO
#define BME_MOSI D2     // SDA
#define BME_CS   D3     // CSB

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

void setup() {
    Serial.begin(115200);

    if (!bme.begin(0x76)) {     // BME280(I2C addr=0x76) begin
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());    // 온도 값 가져와서 출력
    Serial.println("*C");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());       // 습도 값 가져와서 출력
    Serial.println("%");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);  // 기압 값 가져와서 출력
    Serial.println("hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA)); // 고도 값 가져와서 출력
    Serial.println("m");

    Serial.println();
    delay(1000);
}
