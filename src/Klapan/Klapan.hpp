#ifndef KLAPAN_HPP
#define KLAPAN_HPP

#include <Arduino.h>

class Klapan
{
	private:
	uint8_t pOpen;
	uint8_t pClose;
	uint8_t pGND;
	
	public:
	Klapan(uint8_t pinOpen, uint8_t pinClose);
	Klapan(uint8_t pinOpen, uint8_t pinClose, uint8_t pinGND);
	~Klapan();
	
	void Open();
	void Close();
};

#endif