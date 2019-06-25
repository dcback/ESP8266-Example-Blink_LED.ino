// DS18B20 Temperature sensor Read&Display
#include <OneWire.h>            // I2C
#include <DallasTemperature.h>  // DS18B20
#include <LiquidCrystal_I2C.h>  // LCD1602

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address(I2C) to 0x27

#define ONE_WIRE_BUS D3 // D3 connect DS18B20(Data) 

OneWire oneWire(ONE_WIRE_BUS);  // Setup a oneWire BUS
DallasTemperature sensors(&oneWire);

void setup() {
    Serial.begin(115200);       // start serial port
    lcd.begin();        // LCD initialize
    sensors.begin();            // Start up the library
}

void loop() {
    // 0 refers to first DS18B20 on the wire
    float tempDS18B20 = sensors.getTempCByIndex(0);

    // LCD1602_I2C Display
    lcd.setCursor(0, 0);    // cursor at x=0, y=0 position
    lcd.print("DS18B20 Sensor");

    lcd.setCursor(0, 1);    // cursor at x=0, y=1 position
    lcd.print("TEMP is: "); lcd.print(tempDS18B20);
    lcd.print(" C");

    // Serial monitor
    Serial.print("DS18B20 Temperature: ");
    Serial.print(tempDS18B20); Serial.println(" *C");
    delay(1000);
}
