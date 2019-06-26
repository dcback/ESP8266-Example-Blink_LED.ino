#include <TM1637Display.h>

#define CLK D3      // TM1637 pin assign
#define DIO D4      // TM1637 pin assign

TM1637Display display(CLK, DIO);

void setup() {
    display.setBrightness(7);       // min(0 ~ max(7)
}

void loop() {
    int numCnt = random(0, 9999);   // random number
    
    // dot position(0x80 -> 0x40 -> 0x20 -> 0x10)
    display.showNumberDecEx(numCnt, 0x40);  
    delay(500);
}
