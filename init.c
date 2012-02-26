#include "modules.h"
#include "globals.h"

void PwmInit(void)
{
	DDRB = 0x06;
    TCCR1A = 1<<COM1A1 | 1<<COM1B1 | 1<<WGM10;
    TCCR1B = 1<CS10;
}
