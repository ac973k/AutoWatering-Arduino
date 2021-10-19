#include "ThermoOut.hpp"

ThermoOut::ThermoOut(uint8_t OneWireBus)
{
	oneWire = new OneWire(OneWireBus);
	sensor = new DallasTemperature(*&oneWire);
	
	sensor->begin();
}

ThermoOut::ThermoOut(uint8_t OneWireBus, uint8_t pinVCC)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	
	oneWire = new OneWire(OneWireBus);
	sensor = new DallasTemperature(*&oneWire);
	
	sensor->begin();
}

ThermoOut::ThermoOut(uint8_t OneWireBus, uint8_t pinVCC, uint8_t pinGND)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	pinMode(pinGND, OUTPUT);
	digitalWrite(pinGND, LOW);
	
	oneWire = new OneWire(OneWireBus);
	sensor = new DallasTemperature(*&oneWire);
	
	sensor->begin();
}

ThermoOut::~ThermoOut()
{
	delete oneWire;
	delete sensor;
}

float ThermoOut::getTemp()
{
	sensor->requestTemperatures();
	
	return sensor->getTempCByIndex(0);
}