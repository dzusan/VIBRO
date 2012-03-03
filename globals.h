//Discrtisation of signal
#define DISCRET 100

//Amplitude
#define AMP_RATE 0.286


//Encoders

typedef struct{
	uint8_t mask;
	uint8_t state;
	uint8_t value;
}Encoder;

Encoder freqEnc = {0x3, 0, 0};
Encoder amplEnc = {0x6, 0, 0};

typedef struct{
	uint16_t freq;
	uint8_t ampl;
	char shape[DISCRET];
}Conf;

Conf use;
uint8_t shapeCount = 0;

//Keyboard
//uint8_t key;

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

MenuItem freqValue  = {"Frequency", amplValue,  FreqHandler};
MenuItem amplValue  = {"Amplitude", shapeValue, AmplHandler};
MenuItem shapeValue = {"Shape",     freqValue,  FreqHandler};
MenuItem saveOption = {"Save",      loadOption, SaveHandler};
MenuItem loadOption = {"Load",      saveOption, LoadHandler};

MenuItem valueItem  = shapeValue;
MenuItem optionItem = loadOption;
