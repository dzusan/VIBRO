//Encoders

typedef struct{
	uint8_t mask;
	uint8_t state;
	uint8_t value;
}Encoder;

Encoder *freq;
Encoder *ampl;


//Keyboard

//uint8_t key;

//Discrtisation of signal
#define DISCRET 100


//Amplitude

uint8_t ampl;
#define AMP_RATE 0.286
