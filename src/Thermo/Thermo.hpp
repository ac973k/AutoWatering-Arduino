#ifndef THERMO_HPP
#define THERMO_HPP

#include <DHT.h>
#include <Arduino.h>

class Thermo
{
	private:
	DHT *dht;
	
	public:
	Thermo(uint8_t dhtPIN, uint8_t dhtType);
	Thermo(uint8_t dhtPIN, uint8_t dhtType, uint8_t pinVCC);
	Thermo(uint8_t dhtPIN, uint8_t dhtType, uint8_t pinVCC, uint8_t pinGND);
	~Thermo();
	
	float getTemp();
	float getHum();
};

#endif