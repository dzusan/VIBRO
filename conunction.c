#include "modules.h"
#include "globals.h"

inline void Furien(void)
{
	if(count_sin != DISCRET) count_sin++; else count_sin = 0;
	if(count_cos != DISCRET) count_cos++; else count_cos = 0;
	OCR1A = sinus[count_sin];
	OCR1B = sinus[count_cos];
}

inline void Separate(void)
{
	uint8_t currentValue = use.shape[shapeCount++];
	
	if(currentValue >= 0) OCR1A = currentValue;
	else OCR1B = -1 * currentValue;
	
}
