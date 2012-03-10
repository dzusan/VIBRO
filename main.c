#include "modules.h"
#include "globals.h"


int main (void)
{

	LcdInit();
	LcdTable("sinus", 0, 0);
	PwmInit();

	while(1)
	{
		if(keyBan_FLAG){ //If action key already pushed in KeyboardDigit
			keyBan_FLAG = 0;
			KeyboardHandler();
		}
		else if(KeyboardScan()) KeyboardHandler();
		
		if(EncoderScan(&freqEnc)) FreqHandler();
		if(EncoderScan(&amplEnc)) AmplHandler();
	}
}


ISR(TIMER2_COMP_vect)
{
	Furien();
	//Separate();
}
