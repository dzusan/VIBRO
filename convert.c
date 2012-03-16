#include "modules.h"
#include "globals.h"

uint8_t ConvertFreq(void)
{
	if(freqEnc.value < MAX_FREQ){
		use.freq = freqEnc.value;
		return 1;
	}
	else freqEnc.value = MAX_FREQ;
	
	return 0;
}

uint8_t ConvertAmpl(void)
{
	if(amplEnc.value < AMPL_DISCRET){
		use.ampl = (uint8_t)amplEnc.value;
		return 1;
	}
	else amplEnc.value = AMPL_DISCRET;
	
	return 1;
}
