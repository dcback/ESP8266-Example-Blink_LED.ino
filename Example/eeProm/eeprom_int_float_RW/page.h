#include <EEPROM.h>

int   isetValue1, isetValue2, isetValue3, isetValue4, isetValue5;
int   ico2Value1, ico2Value2, ico2Value3, ico2Value4, ico2Value5;
int   ihumiValue1, ihumiValue2, ihumiValue3, ihumiValue4, ihumiValue5;
float fgtempValue1, fgtempValue2, fgtempValue3, fgtempValue4, fgtempValue5;
float ftempValue1, ftempValue2, ftempValue3, ftempValue4, ftempValue5;

int eeAddr[100] = {   4*1,   4*2,  4*3,  4*4, 4*5
                   ,  4*6,   4*7,  4*8,  4*9, 4*10
                   , 4*11,  4*12, 4*13, 4*14, 4*15
                   , 4*16,  4*17, 4*18, 4*19, 4*20
                   , 4*21,  4*22, 4*23, 4*24, 4*25
                  };
