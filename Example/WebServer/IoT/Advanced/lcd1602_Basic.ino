/******************************************
    I2C    Arduino  STM32F103  ESP8266
    SDA      A4        PB7     D2(GPIO4)
    SCL      A5        PB6     D1(GPIO5)
*******************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16x2 display

void setup() {
    lcd.inti();        // LCD initialize
    lcd.backlight();    // Backlight on

    lcd.print("ABCDEFGHIJKLMNOP");  // ABCDEFGHIJKLMNOP Print
    lcd.setCursor(0, 1);            // LCD x=0, y=1 point cursor
    lcd.print("QRSTUVWXYZ012345");  // QRSTUVWXYZ012345 Print
    lcd.noDisplay();                // LCD Off
    delay(500);
    lcd.display();                  // LCD On
    delay(500);
}

void loop() {
}
