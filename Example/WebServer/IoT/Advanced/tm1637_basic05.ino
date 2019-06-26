#include <TM1637Display.h>

#define CLK D3      // TM1637 pin assign
#define DIO D4      // TM1637 pin assign

TM1637Display display(CLK, DIO);

byte data[][4] = {
    { 0x01, 0x00, 0x00, 0x08 },
    { 0x00, 0x01, 0x08, 0x00 },
    { 0x00, 0x08, 0x01, 0x00 },
    { 0x08, 0x00, 0x00, 0x01 },
    { 0x10, 0x00, 0x00, 0x02 },
    { 0x20, 0x00, 0x00, 0x04 }
};

void setup() {
    display.setBrightness(7);
}

void loop() {
    for (int i = 0; i < 6; i++) {
        display.setSegments(data[i]);
        delay(20);
    }
}
