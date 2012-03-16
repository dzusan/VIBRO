#include "modules.h"
#include "globals.h"

uint8_t FreqHandler(void)
{
        TIMSK=(1<<OCIE2); //Timer-2

        uint16_t ticks = F_CPU / (use.freq*DISCRET);
        uint8_t tickPeriod;
        uint16_t cycle=0; //Overflow cycles
        while(1)
        {
            if ((uint16_t)(ticks/256) <= cycle)
            {
                if (cycle == 0) //Prescaler - 1
                {
                    TCCR2 = 1 << CS00;
                    tickPeriod = ticks;
                    break;
                }
                if ((cycle >= 1) && (cycle < 8)) //Prescaler - 8
                {
                    TCCR2 = 1 << CS01;
                    tickPeriod = ticks/8;
                    break;
                }
                if ((cycle >= 8) && (cycle < 32)) //Prescaler - 32
                {
                    TCCR2 = 1 << CS01 | 1 << CS00;
                    tickPeriod = ticks/32;
                    break;
                }
                if ((cycle >= 64) && (cycle < 64)) //Prescaler - 64
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
