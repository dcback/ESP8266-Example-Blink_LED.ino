/******************************************
    I2C    Arduino  STM32F103  ESP8266
    SDA      A4        PB7     D2(GPIO4)
    SCL      A5        PB6     D1(GPIO5)
    
    DHT : Vcc(3.3V), DTH11(D4), DHT22(D3)
*******************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address(I2C) to 0x27

//DHT11
#define DHTPIN11 D4         // what pin we're connected to
#define DHTTYPE11 DHT11     // DHT 11
DHT dht11(DHTPIN11, DHTTYPE11);

//DHT22
#define DHTPIN22 D3         // what pin we're connected to
#define DHTTYPE22 DHT22     // DHT 22
DHT dht22(DHTPIN22, DHTTYPE22);

void setup() {
    Serial.begin(115200);
    dht11.begin();
    dht22.begin();

    lcd.begin();        // LCD initialize
    lcd.backlight();    // Backlight on
}

void loop() {
    delay(2000);

    // Read DHT11 temperature as Celsius
    float tempDHT11 = dht11.readTemperature();
    float humiDHT11 = dht11.readHumidity();
    float f1 = dht11.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(humiDHT11) || isnan(tempDHT11) || isnan(f1)) {
        Serial.println("Failed to read from DHT22 sensor!");
        return;
    }

    // LCD1602_I2C Display
    lcd.setCursor(0, 0);    // cursor at x=0, y=0 position
    lcd.print("Temperat:"); lcd.print(tempDHT11);
    lcd.print(" C");

    lcd.setCursor(0, 1);    // cursor at x=0, y=1 position
    lcd.print("Humidity:"); lcd.print(humiDHT11);
    lcd.print(" %");

    // Serial monitor
    Serial.print("DHT11 Temperature: ");
    Serial.print(tempDHT11); Serial.print(" *C");
    Serial.print("\t Humidity: ");
    Serial.print(humiDHT11); Serial.println(" %");
}
