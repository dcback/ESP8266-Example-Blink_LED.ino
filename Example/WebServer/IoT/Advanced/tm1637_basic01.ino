#include <TM1637Display.h>

#define CLK D3      // TM1637 pin assign
#define DIO D4      // TM1637 pin assign

TM1637Display dsp(CLK, DIO);

void setup() {
    dsp.setBrightness(15);       // min(0 ~ max(7)
}

void loop() {
    int numCnt = random(0, 9999);   // random number;
    dsp.showNumberDec(numCnt);      // display numCnt value
    delay(1000);
}
