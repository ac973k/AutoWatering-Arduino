#include "WaterControle.hpp"

WaterControle *controle;

void setup() {

  controle = new WaterControle;
  controle->setupHumLimit(300, 600);

  //controle->setupDateAndTime(15, 8, 2021, 15, 21, 10); //Example: controle->setupDateAndTime(day, month, year, hours, minutes, seconds);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //controle->printTempAndHum();
  //controle->printDateAndTime();
  //controle->printInform();
  //controle->onUpdate();
  
  controle->test();
  delay(2000);
}
