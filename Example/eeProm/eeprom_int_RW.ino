#include <EEPROM.h>

int  isetValue1, isetValue2, isetValue3, isetValue4, isetValue5;

void setup() {
    Serial.begin(115200);
    EEPROM.begin(512);  //EEPROM.begin(Size)
}

int EEaddress[5] = { 0, };

void loop() {

    EEaddress[0] = 4;   // must int(4) size interval
    EEaddress[1] = 8;
    EEaddress[2] = 12;
    EEaddress[3] = 16;
    EEaddress[4] = 20;

    isetValue1 = 11111111;
    isetValue2 = 22222222;
    isetValue3 = 33333333;
    isetValue4 = -44444444;
    isetValue5 = -55555555;

    EEPROM.put(EEaddress[0], isetValue1);
    EEPROM.put(EEaddress[1], isetValue2);
    EEPROM.put(EEaddress[2], isetValue3);
    EEPROM.put(EEaddress[3], isetValue4);
    EEPROM.put(EEaddress[4], isetValue5);
    EEPROM.commit();

    isetValue1 = 0; // To prove it read from EEPROM!
    isetValue2 = 0; // To prove it read from EEPROM!
    isetValue3 = 0; // To prove it read from EEPROM!
    isetValue4 = 0; // To prove it read from EEPROM!
    isetValue5 = 0; // To prove it read from EEPROM!

    EEPROM.get(EEaddress[0], isetValue1);
    EEPROM.get(EEaddress[1], isetValue2);
    EEPROM.get(EEaddress[2], isetValue3);
    EEPROM.get(EEaddress[3], isetValue4);
    EEPROM.get(EEaddress[4], isetValue5);
    
    Serial.println(isetValue1);
    Serial.println(isetValue2);
    Serial.println(isetValue3);
    Serial.println(isetValue4);
    Serial.println(isetValue5);
    delay(1000);
}
