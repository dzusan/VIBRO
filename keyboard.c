#include "modules.h"
#include "globals.h"

uint8_t KeyboardScan()
{
	_DDR_KB=0x0F;
    _PORT_KB=0xF0;
    _delay_us(1);
    uint8_t k=4;
    if ((_PIN_KB&0x10)==0) k=0;
    if ((_PIN_KB&0x20)==0) k=1;
    if ((_PIN_KB&0x40)==0) k=2;
    if ((_PIN_KB&0x80)==0) k=3;

    _DDR_KB=0xF0;
    _PORT_KB=0x0F;
    _delay_us(1);
    uint8_t i=4;
    if ((_PIN_KB&0x01)==0) i=0;
    if ((_PIN_KB&0x02)==0) i=1;
    if ((_PIN_KB&0x04)==0) i=2;
    if ((_PIN_KB&0x08)==0) i=3;

    if ((i!=4)&&(k!=4))
    {
        while(_PIN_KB!=0x0F) _delay_us(1);

        uint8_t matrix[4][4]={{'*', 0 ,'#','D'},
                           { 7 , 8 , 9 ,'C'},
                           { 2 , 5 , 6 ,'B'},
                           { 1 , 2 , 3 ,'A'}};
                           
     scanKey = matrix[i][k];
     return 1;
     }
     
     return 0;
}
