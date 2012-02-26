#include "modules.h"
#include "globals.h"

uint8_t KeyboardHandler(void)
{
	swich(KeyboardScan()){
		case 'A':
			Menu(a);
		case 'B':
			Menu(b);
		case '8':
			Menu(up);
		case '6':
			Menu(left);
		case '2':
			Menu(down);
		case '4':
			Menu(right);
	}
	
	return 1;
}

			
uint8_t FreqHandler(void)
{
//Frequency configure

        TIMSK=(1<<OCIE2); //Timer-2

        uint16_t ticks = F_CPU / (freq.value*DISCRET);
        uint8_t tickPeriod;
        uint16_t cycle=0; //Overflow cycles
        while(1)
        {
            if ((uint16_t)ticks/256 <= cycle)
            {
                if (cycle==0) //Prescaler - 1
                {
                    TCCR2=1<<CS00;
                    tickPeriod = ticks;
                    break;
                }
                if ((cycle > 1) && (cycle <= 8)) //Prescaler - 8
                {
                    TCCR2=1<<CS01;
                    tickPeriod = ticks/8;
                    break;
                }
                if ((cycle > 8) && (cycle <= 32)) //Prescaler - 32
                {
                    TCCR2 = 1 << CS01 | 1 << CS00;
                    tickPeriod = ticks/32;
                    break;
                }
                if ((cycle > 64) && (cycle <= 64)) //Prescaler - 64
                {
                    TCCR2 = 1 << CS02;
                    tickPeriod = ticks/64;
                    break;
                }
            }
            cycle ++;
        }

        OCR2 = tickPeriod;
        return 1;
}

uint8_t AmplHandler(void)
{
	ampl = ampl.value * AMP_RATE;
	return 1;
}
