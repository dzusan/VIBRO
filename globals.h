//Encoders

/*typedef struct{
	uint8_t mask;
	uint8_t state;
	uint8_t value;
}Encoder;

Encoder *freq;
Encoder *ampl;*/

typedef struct{
	uint16_t freq;
	uint8_t ampl;
	char shape[DISCRET];
}Conf;


//Keyboard

//uint8_t key;

//Discrtisation of signal
#define DISCRET 100


//Amplitude

uint8_t ampl;
#define AMP_RATE 0.286

//Menu items
enum item{
	VALUES;
	EE_MEMORY;
	COMPUTER_CONNECTION;
	START_STOP;
	UP;
	DOWN;
};

typedef struct PROGMEM{
	char *name;
	menuItem *next;
	void (*action)(void);
}MenuItem;

MenuItem freqValue  {"Frequency", amplValue,  FreqHandler};
MenuItem amplValue  {"Amplitude", shapeValue, AmplHandler};
MenuItem shapeValue {"Shape",     freqValue,  FreqHandler};
MenuItem saveOption {"Save",      loadOption, SaveHandler};
MenuItem loadOption {"Load",      saveOption, LoadHandler};

MenuItem valueItem;
MenuItem optionItem;
