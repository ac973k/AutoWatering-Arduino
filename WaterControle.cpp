#include "WaterControle.hpp"

WaterControle::WaterControle()
{	
	thermo = new Thermo(tPIN, tType, tVCC, tGND); //pin, DHT Version [DHT11, DHT22], pinVCC, pinGND
	lcd = new Display(dAddress, dCol, dRow); //Address, colomn, row
	dt = new DateTime(dt_DataPin, dt_SclkPin); //SDA, SCL pins
	to = new ThermoOut(to_OneWireBus, to_pinVCC, to_pinGND); //Data Pin DS18B20, pinVCC, pinGND
	klapan = new Klapan(k_pinOpen, k_pinClose, k_pinGND); //uint8_t pinOpen, uint8_t pinClose, pinGND
	sensor = new CapasitiveSoilSensor(s_pinVCC, s_pinGND, s_AOut); //pinVCC, pinGND, pinAOut
	
	isOpen = false; //Klapan. Open = true, Close = false
	
	Serial.begin(115200);
}

WaterControle::~WaterControle()
{
	delete sensor;
	delete klapan;
	delete to;
	delete dt;
	delete lcd;
	delete thermo;
}

void WaterControle::printTempAndHum()
{
	count = 5;
	
	while (count) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("T = ", thermo->getTemp());
		Serial.print("T = ");
		Serial.print(thermo->getTemp());
		Serial.print("\n");

		lcd->setStr(0, 1);
		lcd->printOnLCD("H = ", thermo->getHum());
		lcd->printOnLCD(" %");
		Serial.print("H = ");
		Serial.print(thermo->getHum());
		Serial.print("\n");

		count--;

		delay(1000);
    
		lcd->lcdClear();
	}
}

void WaterControle::printDateAndTime()
{
	count = 5;
	
	while (count) {

		lcd->setStr(0, 0);
		lcd->printOnLCD(dt->getDate().c_str());
		Serial.print(dt->getDate().c_str());
		Serial.print("\n");

		lcd->setStr(0, 1);
		lcd->printOnLCD(dt->getTime().c_str());
		Serial.print(dt->getTime().c_str());
		Serial.print("\n");

		count--;

		delay(1000);

		lcd->lcdClear();
	}
}

void WaterControle::printTempOnOut() {
	count = 5;
	
	while (count) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("Temp on Out:");
		Serial.print("Temp on Out:");
		Serial.print(to->getTemp());
		Serial.print("\n");

		lcd->setStr(0, 1);
		lcd->printOnLCD(to->getTemp());
		lcd->printOnLCD(" C");
		Serial.print(to->getTemp());

		count--;

		delay(1000);
    
		lcd->lcdClear();
	}
}

void WaterControle::printInform()
{
	if (isOpen == false) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("Water Close");
		lcd->setStr(0, 1);
		lcd->printOnLCD("by Danilka =)");
	}
	else if (isOpen == true) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("Water Open");
		lcd->setStr(0, 1);
		lcd->printOnLCD("by Danilka =)");
	}

	delay(5000);
	lcd->lcdClear();
}

void WaterControle::setupDateAndTime(uint8_t date, uint8_t mon, uint16_t year, uint8_t hour, uint8_t min, uint8_t sec)
{
	dt->setDate(date, mon, year);
	dt->setTime(hour, min, sec);              //  Установить время 16:29:00 (формат 24 часа)
}

void WaterControle::setupLimits(float aMaxTemp, float aMinTemp, float aMaxHum, float aMinHum)
{
	MaxTemp = aMaxTemp;
	MinTemp = aMinTemp;
	MaxHum = aMaxHum;
	MinHum = aMinHum;
}

void WaterControle::setupHumLimit(int MIN, int MAX)
{
	MinGr = MIN;
	MaxGr = MAX;
}

void WaterControle::onUpdate()
{	
	if (sensor->getData(s_AOut) <= MinGr) {
		if (isOpen == false) {
			klapan->Open();
			delay(15000);
		}
		else if (isOpen == true) {
			delay(1000);
		}
	}
	else if (sensor->getData(s_AOut) >= MaxGr) {
		if (isOpen == false) {
			delay(1000);
		}
		else if (isOpen == true) {
			klapan->Close();
			delay(15000);
		}
	}
}

void WaterControle::test()
{
	lcd->setStr(0, 0);
	lcd->printOnLCD("Max Ground:", MaxGr);
	lcd->setStr(0, 1);
	lcd->printOnLCD("Min Ground:", MinGr);
	
	Serial.print("Max Ground: ");
  Serial.print(MaxGr);
	Serial.print("\n");
	Serial.print("Min Ground:");
 Serial.print(MinGr);
	Serial.print("\n");
	
	delay(5000);
	lcd->lcdClear();
	
	lcd->setStr(0, 0);
	lcd->printOnLCD("Current Data");
	lcd->setStr(0, 1);
	lcd->printOnLCD(sensor->getData(s_AOut));
	
	Serial.print("Current Data: ");
  Serial.print(sensor->getData(s_AOut));
	Serial.print("\n");
	
	delay(5000);
	lcd->lcdClear();
}
