#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#define F_CPU 16000000
#include <util/delay.h>

//encoders.c
uint8_t EncoderScan(Encoder *);

//handlers.c
uint8_t FreqHandler(void);

//init.c
void PwmInit(void);

//conunction.c
inline void Furien(void);
inline void Separate(void);

//convert.c
uint8_t ConvertAmpl(void);
uint8_t ConvertFreq(void);
