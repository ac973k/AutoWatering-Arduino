#ifndef CAPASITIVESOILSENSOR_HPP
#define CAPASITIVESOILSENSOR_HPP

#include <Arduino.h>



class CapasitiveSoilSensor
{
	private:
	uint16_t sensor;
	
	public:
	CapasitiveSoilSensor(int AOut);
	CapasitiveSoilSensor(int pinVCC, int AOut);
	CapasitiveSoilSensor(int pinVCC, int pinGND, int AOut);
	~CapasitiveSoilSensor();
	
	int getData(int sensor);
};

#endif