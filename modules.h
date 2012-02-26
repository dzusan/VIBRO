#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#define F_CPU 16000000
#include <util/delay.h>

//encoders.c
uint8_t EncoderScan(Encoder *);

//handlers.c
uint8_t KeyboardHandler(void);
uint8_t FreqHandler(void);
uint8_t AmplHandler(void);

//keyboard.c
uint8_t KeyboardScan(void);

//init.c
void PwmInit(void);

//conunction.c
void Furien(void);
void Separate(void);
