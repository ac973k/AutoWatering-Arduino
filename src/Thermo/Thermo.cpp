#include "Thermo.hpp"

Thermo::Thermo(uint8_t dhtPIN, uint8_t dhtType)
{
	dht = new DHT(dhtPIN, dhtType);
	dht->begin();
}

Thermo::Thermo(uint8_t dhtPIN, uint8_t dhtType, uint8_t pinVCC)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	
	dht = new DHT(dhtPIN, dhtType);
	dht->begin();
}

Thermo::Thermo(uint8_t dhtPIN, uint8_t dhtType, uint8_t pinVCC, uint8_t pinGND)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	pinMode(pinGND, OUTPUT);
	digitalWrite(pinGND, LOW);
	
	dht = new DHT(dhtPIN, dhtType);
	dht->begin();
}

Thermo::~Thermo()
{
	delete dht;
}

float Thermo::getTemp()
{
	return dht->readTemperature();
}

float Thermo::getHum()
{
	return dht->readHumidity();
}