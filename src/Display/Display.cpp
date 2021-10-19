#include "Display.hpp"

Display::Display(uint8_t address, uint8_t col, uint8_t row)
{
	lcd = new LiquidCrystal_I2C(address, col, row);
	
	lcd->init();
	lcd->backlight();
}

Display::Display(uint8_t address, uint8_t col, uint8_t row, uint8_t pinVCC)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	
	lcd = new LiquidCrystal_I2C(address, col, row);
	
	lcd->init();
	lcd->backlight();
}

Display::Display(uint8_t address, uint8_t col, uint8_t row, uint8_t pinVCC, uint8_t pinGND)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	pinMode(pinGND, OUTPUT);
	digitalWrite(pinGND, LOW);
	
	lcd = new LiquidCrystal_I2C(address, col, row);
	
	lcd->init();
	lcd->backlight();
}

Display::~Display()
{
	delete lcd;
}

void Display::printOnLCD(char text[100])
{
	lcd->print(text);
}

void Display::printOnLCD(float num)
{
	lcd->print(num);
}

void Display::printOnLCD(char text[100], float num)
{
	lcd->print(text);
	lcd->print(num);
}

void Display::setStr(uint8_t colomn, uint8_t row)
{
	lcd->setCursor(colomn, row);
}

void Display::lcdClear()
{
	lcd->clear();
}