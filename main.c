#include "modules.h"
#include "globals.h"


int main (void)
{

	LcdInit();
	LcdTable("sinus", 0, 0);
	PwmInit();

	while(1)
	{		
		if(EncoderScan(&freqEnc)){ //Write freq-control value in EncSruct
			ConvertFreq(); //Overflow verification (default)
			FreqHandler(); //Timer configuration
			LcdTable(use.freq, use.ampl, "sinus"); //Dysplay
		}
		
		if(EncoderScan(&amplEnc)){ 
			ConvertAmpl();
			LcdTable(use.freq, use.ampl, "sinus");
		}
	}
}


ISR(TIMER2_COMP_vect)
{
	//Furien();
	Separate();
}
