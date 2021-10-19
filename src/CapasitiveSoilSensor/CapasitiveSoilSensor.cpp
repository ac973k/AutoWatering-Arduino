#include "CapasitiveSoilSensor.hpp"

CapasitiveSoilSensor::CapasitiveSoilSensor(int AOut)
{
	int sensor = analogRead(AOut);
}

CapasitiveSoilSensor::CapasitiveSoilSensor(int pinVCC, int AOut)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	
	int sensor = analogRead(AOut);
}

CapasitiveSoilSensor::CapasitiveSoilSensor(int pinVCC, int pinGND, int AOut)
{
	pinMode(pinVCC, OUTPUT);
	digitalWrite(pinVCC, HIGH);
	pinMode(pinGND, OUTPUT);
	digitalWrite(pinGND, LOW);
	
	int sensor = analogRead(AOut);
}

CapasitiveSoilSensor::~CapasitiveSoilSensor()
{
	
}

int CapasitiveSoilSensor::getData(int sensor)
{
	delay(50);
	return analogRead(sensor);
}