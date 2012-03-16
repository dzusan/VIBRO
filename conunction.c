#include "modules.h"
#include "globals.h"

inline void Furien(void)
{
	if(countSin != DISCRET) countSin++; else countSin = 0;
	if(countCos != DISCRET) countCos++; else countCos = 0;
	OCR1A = (uint8_t)(64 + sinus[countSin] * use.ampl);
	OCR1B = (uint8_t)(64 + sinus[countCos] * use.ampl);
}

inline void Separate(void)
{
	uint8_t currentValue = use.shape[shapeCount++];
	
	if(currentValue >= 0) OCR1A = currentValue;
	else OCR1B = -1 * currentValue;
	
}
