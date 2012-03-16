//Discrtisation of signal
#define DISCRET 100

//Sinus to cosinus shift
#define SHIFT 25

//Amplitude qualty
#define AMPL_DISCRET 60

//Maximal frequency of main signal
#define MAX_FREQ 2000

//Encoders

typedef struct{
	uint8_t mask;
	uint8_t state;
	uint16_t value;
}Encoder;

volatile Encoder freqEnc = {0x3, 0, 0};
volatile Encoder amplEnc = {0x6, 0, 0};

//Data
typedef struct{
	uint16_t freq;
	uint8_t ampl;
	char shape[DISCRET];
}Data;

volatile Data use;

//Separate shape count
volatile uint8_t shapeCount = 0;

//Furien shape count
volatile uint8_t countSin = 0;
volatile uint8_t countCos = SHAPE;
