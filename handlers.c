#include "modules.h"
#include "globals.h"

uint8_t KeyboardHandler(void *KB_value)
{
	uint8_t key;
	
	swich(scanKey){
		case VALUES:
			valueItem = valueItem -> next;
			print(valueItem -> name, '/n');
			valueItem -> (*action)();
			return KB_value;
			
		case EE_MEMORY:
			optionItem = optionItem -> next;
			print(optionItem -> name, '/n');
			optionItem -> (*action)();
			return KB_value;
			
		case COMPUTER_CONNECTION:
			print("Comp connect");
			return KB_value;
			
		case START_STOP:
			StartStop();
			return KB_value;
			
		case UP:
			if(KB_value) KB_value++;
			print(cleanline);
			print(itoa(KB_value);
			return KB_value;
			
		case DOWN:
			if(KB_value) KB_value--;
			print(cleanline);
			print(itoa(KB_value);
			return KB_value;
			
		case '0'...'9':
			if(KB_value){
				KB_value = 10 * KB_value + atoi(key);
				print(cleanline);
				print(itoa(KB_value);
				KeyboardHandler(&KB_value);
		
		default: return 0;
	}
}

uint8_t FreqHandler(void)
{
        TIMSK=(1<<OCIE2); //Timer-2

        uint16_t ticks = F_CPU / (use.freq*DISCRET);
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
                if ((cycle >= 1) && (cycle < 8)) //Prescaler - 8
                {
                    TCCR2=1<<CS01;
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

uint8_t AmplHandler(void)
{
	use.ampl = amplEnc.value * AMP_RATE;
	return 1;
}
