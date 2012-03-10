#include "modules.h"
#include "globals.h"


uint8_t KeyboardAction()
{
	switch(scanKey){
		
		case VALUES:
			valueItem = valueItem -> next;
			print(valueItem -> name, '/n');
			valueItem -> (*action)();
			return 1;
			
		case EE_MEMORY:
			optionItem = optionItem -> next;
			print(optionItem -> name, '/n');
			optionItem -> (*action)();
			return 1;
			
		case COMPUTER_CONNECTION:
			print("Comp connect");
			return 1;
			
		case START_STOP:
			StartStop();
			return 1;
	}
	
	return 0;
}

		
uint8_t KeyboardDigit(void *KB_value)
{	
	while(!KeyboardScan);
	
	switch(scanKey){
		
		case UP:
			KB_value++;
			print(cleanline);
			print(itoa(KB_value));
			KeyboardHandler(&KB_value);
			
		case DOWN:
			KB_value--;
			print(cleanline);
			print(itoa(KB_value));
			KeyboardHandler(&KB_value);
			
		case '0'...'9':
			KB_value = 10 * KB_value + atoi(key);
			print(cleanline);
			print(itoa(KB_value);
			KeyboardHandler(&KB_value);
			
		default: 
			keyBan_FLAG = 1;
			return 1;
	}
	
	return 0;
}


uint8_t FreqHandler(void)
{
        TIMSK=(1<<OCIE2); //Timer-2

        uint16_t ticks = F_CPU / (freq.value*DISCRET);
        uint8_t tickPeriod;
        uint16_t cycle=0; //Overflow cycles
        while(1)
        {
            if ((uint16_t)ticks/256 <= cycle)
            {
                if (cycle == 0) //Prescaler - 1
                {
                    TCCR2 = 1 << CS00;
                    tickPeriod = ticks;
                    break;
                }
                if ((cycle > 1) && (cycle <= 8)) //Prescaler - 8
                {
                    TCCR2 = 1 << CS01;
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
	use.ampl = amplEnc.value;
	return 1;
}
