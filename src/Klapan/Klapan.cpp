#include "Klapan.hpp"

Klapan::Klapan(uint8_t pinOpen, uint8_t pinClose) {
	pOpen = pinOpen;
	pClose = pinClose;
	
	pinMode(pinOpen, OUTPUT);
	pinMode(pinClose, OUTPUT);
}

Klapan::Klapan(uint8_t pinOpen, uint8_t pinClose, uint8_t pinGND) {
	pOpen = pinOpen;
	pClose = pinClose;
	pGND = pinGND;
	
	pinMode(pinOpen, OUTPUT);
	pinMode(pinClose, OUTPUT);
	
	pinMode(pinGND, OUTPUT);
	digitalWrite(pinGND, LOW);
}

Klapan::~Klapan() {
	
}

void Klapan::Open() {
	digitalWrite(pClose, LOW);    
	delay(1000);
	digitalWrite(pOpen, HIGH);   
	delay(1000);
}

void Klapan::Close() {
	digitalWrite(pOpen, LOW);    
	delay(1000);
	digitalWrite(pClose, HIGH);   
	delay(1000);
}