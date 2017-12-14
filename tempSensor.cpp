// --- tempSensor.cpp ---

#include <iostream>
#include "tempSensor.h"

using namespace std;

tempSensor::tempSensor(int ID, bool status, int sense_interval, double temperature1) : 
        	Sensor(ID, status, sense_interval) {
	temperature = temperature1;
}

double tempSensor::getTemp() const {
	return temperature;	
}


