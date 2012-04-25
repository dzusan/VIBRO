#include "modules.h"
#include "globals.h"

void Transfer (uint8_t lcd)
{
 PORTD |= (1<<E);
  PORTB = (lcd>>4);	                //Âûâîäèì ñòàðøóþ òåòðàäó êîìàíäû
  _delay_us(1);	                //Çàäåðæêà
  PORTD &=~(1<<E);	        //Ñèãíàë çàïèñè êîìàíäû
  _delay_us(1);
  PORTD |= (1<<E);
  PORTB = (lcd&0x0F);	                   //Âûâîäèì ìëàäøóþ òåòðàäó êîìàíäû
  _delay_us(1);	                   //Çàäåðæêà
  PORTD &=~(1<<E);	           //Ñèãíàë çàïèñè êîìàíäû

  _delay_ms(1);	        //Ïàóçà äëÿ âûïîëíåíèÿ êîìàíäû
}


void LcdCom (uint8_t lcd)
{
  PORTD &=~(1<<RS);		//RS=0  ýòî êîìàíäà
  Transfer(lcd);
}

void LcdDat (uint8_t lcd)
{
  PORTD =(1<<RS);		//RS=1  ýòî äàííûå
  Transfer(lcd);
}


void LcdInit (void)
{
  LcdCom(0x28);   //4-ïðîâîäíûé èíòåðôåéñ, 5x8 ðàçìåð ñèìâîëà
 _delay_ms(5);
 LcdCom(0x0C);		//Ïîêàçàòü èçîáðàæåíèå, êóðñîð íå ïîêàçûâàòü
 _delay_ms(5);
 LcdCom(0x01);		//Î÷èñòèòü DDRAM è óñòàíîâèòü êóðñîð íà 0x00
 _delay_ms(5);
}

void Puts (char *str)
{
	uint8_t size = strlen(str);
	uint8_t count;
	for (count = 0; count < size; count++) LcdDat(str[count]);
}

uint8_t CursorPosition(uint8_t y, x)
{
	LcdCom(...); // (0;0) position command
	if(y == 2) LcdCom(0x0c);
	for(count = 0; count < x, count++) LcdCom(0x14);
}

uint8_t LcdTableInit(void)
{
	uint8_t count;
	
	Puts("F:");
	for(count = 0; count < 6, count++) LcdCom(0x14);
	Puts("Hz");
	for(count = 0; count < 2, count++) LcdCom(0x14);
	Puts("%");
	
	
uint8_t LcdTable(uint16_t freq, uint8_t ampl, uint8_t *shape)
{
	
