#include <TM1637Display.h>

#define CLK D3      // TM1637 pin assign
#define DIO D4      // TM1637 pin assign

const uint8_t c[] = {   // Custom char setting
    0x0, 0x0, 0x0,
    SEG_A | SEG_F | SEG_G,
};

TM1637Display display(CLK, DIO);

void setup() {
    display.setBrightness(7);   // min(0) ~ max(7)
}

void loop() {
    int numCnt = 123;

// numCnt(표시숫자) false(0제외)/true(0표시) 3(숫자길이) 1(표시위치, 왼쪽->오른쪽:0~3)
    display.showNumberDec(numCnt, false, 3, 0); // display numCnt value
    display.setSegments(c);

    // colon/dot Display
    uint8_t segto;
    segto = 0x80;
    display.setSegments(&segto, 1, 1);  // &segto, on(1)/off(0), position(0~2)
}
