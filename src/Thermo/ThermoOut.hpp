#ifndef THERMOOUT_HPP
#define THERMOOUT_HPP

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

class ThermoOut
{
	private:
	OneWire *oneWire;
	DallasTemperature *sensor;
	
	public:
	ThermoOut(uint8_t OneWireBus);
	ThermoOut(uint8_t OneWireBus, uint8_t pinVCC);
	ThermoOut(uint8_t OneWireBus, uint8_t pinVCC, uint8_t pinGND);
	~ThermoOut();
	
	float getTemp();
};

#endif