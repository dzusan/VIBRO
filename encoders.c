#include "modules.h"
#include "globals.h"

uint8_t EncoderScan(Encoder *Changer)
{
	uint8_t newValue = PINC & Changer -> mask;
	uint8_t fullState = newValue | Changer -> state << 2;

	switch(fullState)
	{
		case 0x2: case 0x4: case 0xB: case 0xD:
			if(Changer -> value < 255) Changer -> value ++;
			Changer -> state = newValue;
			return 1;

		case 0x1: case 0x7: case 0x8: case 0xE:
			if(Changer -> value > 1) Changer -> value --;
			Changer -> state = newValue;
			return 1;
	}
	return 0;
}
