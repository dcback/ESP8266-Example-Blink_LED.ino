/******************************************
    I2C    Arduino  STM32F103  ESP8266
    SDA      A4        PB7     D2(GPIO4)
    SCL      A5        PB6     D1(GPIO5)

    HTU21D : VCC(3.3V)
*******************************************/
#include <Wire.h>
#include "SparkFunHTU21D.h"

HTU21D mySENSOR;    // HTU21D Sensor Define to mySENSOR

void setup() {
    Serial.begin(115200);

    mySENSOR.begin();
}

void loop() {
    float tempVal = mySENSOR.readTemperature();
    float humiVal = mySENSOR.readHumidity();

    Serial.print("HTU21D Temperature: ");
    Serial.print(tempVal, 1);
    Serial.print(" *C   ");
    Serial.print("Humidity: ");
    Serial.print(humiVal, 1);
    Serial.println(" %");

    delay(1000);
}
