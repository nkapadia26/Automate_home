// --- windowSensor.cpp ---

#include <iostream>
#include "windowSensor.h"

using namespace std;

windowSensor::windowSensor(int ID, bool status, int sense_interval, int open_level) :
		Sensor (ID, status, sense_interval) {
	this->open_level = open_level;
}

int windowSensor::getLevel() const {
	return open_level;
}

