#ifndef WATERCONTROLE_HPP
#define WATERCONTROLE_HPP

#include "src/Thermo/Thermo.hpp"
#include "src/Thermo/ThermoOut.hpp"
#include "src/Display/Display.hpp"
#include "src/Date/Date.hpp"
#include "src/Klapan/Klapan.hpp"
#include "src/CapasitiveSoilSensor/CapasitiveSoilSensor.hpp"

class WaterControle
{
	private:
	Thermo *thermo;
	Display *lcd;
	DateTime *dt;
	ThermoOut *to;
	Klapan *klapan;
	CapasitiveSoilSensor *sensor;
	
	/*
	Thermo sensor inside
	*/
	uint8_t tPIN = 3;
	uint8_t tType = DHT11;
	uint8_t tVCC = 2;
	uint8_t tGND = 4;
	
	/*
	LCD I2C Display Setup
	*/
	
	uint8_t dAddress = 0x3F;
	uint8_t dCol = 16;
	uint8_t dRow = 2;
	uint8_t dVCC = NULL;
	uint8_t dGND = NULL;
	
	/*
	Date and Time Setup
	*/
	
	uint8_t dt_DataPin = A4;
	uint8_t dt_SclkPin = A5;
	uint8_t dt_PinVCC = NULL;
	uint8_t dt_PinGND = NULL;
	
	/*
	Thermo sensor outside
	*/
	
	uint8_t to_OneWireBus = 8;
	uint8_t to_pinVCC = 9;
	uint8_t to_pinGND = 10;
	
	/*
	Water Klapan Setup
	*/
	
	uint8_t k_pinOpen = 6;
	uint8_t k_pinClose = 5;
	uint8_t k_pinGND = 7;
	
	/*
	Soil Sensor Setup
	*/
	
	int s_pinVCC = A0;
	int s_pinGND = A1;
	int s_AOut = A2;
	
	/*
	Max and Min temp and Hum for opened window
	*/
	
	float MaxTemp;
	float MinTemp;
	float MaxHum;
	float MinHum;
	
	/*
	Max and Min Hum Ground
	*/
	
	int MinGr;
	int MaxGr;
	
	/*
	Open Klapan? true or false
	*/
	
	bool isOpen;
	
	/*
	seconds
	*/
	
	uint8_t count;
	
	public:
	WaterControle();
	~WaterControle();
	
	void printTempAndHum();
	void printDateAndTime();
	void printTempOnOut();
	void printInform();
	
	void setupDateAndTime(uint8_t date, uint8_t mon, uint16_t year, uint8_t hour, uint8_t min, uint8_t sec);
	void setupLimits(float aMaxTemp, float aMinTemp, float aMaxHum, float aMinHum);
	void setupHumLimit(int MIN, int MAX);
	
	void onUpdate();
	
	void test();
};

#endif
