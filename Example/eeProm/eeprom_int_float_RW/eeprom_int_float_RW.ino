#include "page.h"

void setup() {
    Serial.begin(115200);
    EEPROM.begin(512);  //EEPROM.begin(Size)
}

void loop() {
    isetValue1 = 1001; isetValue2 = 1002; isetValue3 = 1003; isetValue4 = -1004; isetValue5 = -1005;
    EEPROM.put(eeAddr[0], isetValue1); EEPROM.put(eeAddr[1], isetValue2); EEPROM.put(eeAddr[2], isetValue3); EEPROM.put(eeAddr[3], isetValue4); EEPROM.put(eeAddr[4], isetValue5);

    ico2Value1 = 2001; ico2Value2 = 2002; ico2Value3 = 2003; ico2Value4 = -2004; ico2Value5 = -2005;
    EEPROM.put(eeAddr[5], ico2Value1); EEPROM.put(eeAddr[6], ico2Value2); EEPROM.put(eeAddr[7], ico2Value3); EEPROM.put(eeAddr[8], ico2Value4); EEPROM.put(eeAddr[9], ico2Value5);

    ihumiValue1 = 10; ihumiValue2 = 20; ihumiValue3 = 30; ihumiValue4 = -40; ihumiValue5 = -50;
    EEPROM.put(eeAddr[10], ihumiValue1); EEPROM.put(eeAddr[11], ihumiValue2); EEPROM.put(eeAddr[12], ihumiValue3); EEPROM.put(eeAddr[13], ihumiValue4); EEPROM.put(eeAddr[14], ihumiValue5);

    fgtempValue1 = 3.10; fgtempValue2 = 3.11; fgtempValue3 = 3.12; fgtempValue4 = -3.13; fgtempValue5 = -3.14;
    EEPROM.put(eeAddr[15], fgtempValue1); EEPROM.put(eeAddr[16], fgtempValue2); EEPROM.put(eeAddr[17], fgtempValue3); EEPROM.put(eeAddr[18], fgtempValue4); EEPROM.put(eeAddr[19], fgtempValue5);

    ftempValue1 = 4.10; ftempValue2 = 4.11; ftempValue3 = 4.12; ftempValue4 = -4.13; ftempValue5 = -4.14;
    EEPROM.put(eeAddr[20], ftempValue1); EEPROM.put(eeAddr[21], ftempValue2); EEPROM.put(eeAddr[22], ftempValue3); EEPROM.put(eeAddr[23], ftempValue4); EEPROM.put(eeAddr[24], ftempValue5);

    EEPROM.commit();

    // To prove it read from EEPROM!
    isetValue1 = 0; isetValue2 = 0; isetValue3 = 0; isetValue4 = 0; isetValue5 = 0;
    ico2Value1 = 0; ico2Value2 = 0; ico2Value3 = 0; ico2Value4 = 0; ico2Value5 = 0;
    ihumiValue1 = 0; ihumiValue2 = 0; ihumiValue3 = 0; ihumiValue4 = 0; ihumiValue5 = 0;
    fgtempValue1 = 0; fgtempValue2 = 0; fgtempValue3 = 0; fgtempValue4 = 0; fgtempValue5 = 0;
    ftempValue1 = 0; ftempValue2 = 0; ftempValue3 = 0; ftempValue4 = 0; ftempValue5 = 0;

    EEPROM.get(eeAddr[0], isetValue1); EEPROM.get(eeAddr[1], isetValue2); EEPROM.get(eeAddr[2], isetValue3); EEPROM.get(eeAddr[3], isetValue4); EEPROM.get(eeAddr[4], isetValue5);
    EEPROM.get(eeAddr[5], ico2Value1); EEPROM.get(eeAddr[6], ico2Value2); EEPROM.get(eeAddr[7], ico2Value3); EEPROM.get(eeAddr[8], ico2Value4); EEPROM.get(eeAddr[9], ico2Value5);
    EEPROM.get(eeAddr[10], ihumiValue1); EEPROM.get(eeAddr[11], ihumiValue2); EEPROM.get(eeAddr[12], ihumiValue3); EEPROM.get(eeAddr[13], ihumiValue4); EEPROM.get(eeAddr[14], ihumiValue5);
    EEPROM.get(eeAddr[15], fgtempValue1); EEPROM.get(eeAddr[16], fgtempValue2); EEPROM.get(eeAddr[17], fgtempValue3); EEPROM.get(eeAddr[18], fgtempValue4); EEPROM.get(eeAddr[19], fgtempValue5);
    EEPROM.get(eeAddr[20], ftempValue1); EEPROM.get(eeAddr[21], ftempValue2); EEPROM.get(eeAddr[22], ftempValue3); EEPROM.get(eeAddr[23], ftempValue4); EEPROM.get(eeAddr[24], ftempValue5);

    Serial.println("[set_Value]");
    Serial.println(isetValue1); Serial.println(isetValue2); Serial.println(isetValue3); Serial.println(isetValue4); Serial.println(isetValue5); Serial.println("[CO2_Value]");
    Serial.println(ico2Value1); Serial.println(ico2Value2); Serial.println(ico2Value3); Serial.println(ico2Value4); Serial.println(ico2Value5); Serial.println("[HUMI_Value]");
    Serial.println(ihumiValue1); Serial.println(ihumiValue2); Serial.println(ihumiValue3); Serial.println(ihumiValue4); Serial.println(ihumiValue5); Serial.println("[gTEMP_Value]");
    Serial.println(fgtempValue1); Serial.println(fgtempValue2); Serial.println(fgtempValue3); Serial.println(fgtempValue4); Serial.println(fgtempValue5); Serial.println("[TEMP_Value]");
    Serial.println(ftempValue1); Serial.println(ftempValue2); Serial.println(ftempValue3); Serial.println(ftempValue4); Serial.println(ftempValue5);

    delay(1000);
}
