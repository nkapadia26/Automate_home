// --- windowSensor.cpp ---

#include <iostream>
#include "windowSensor.h"

using namespace std;

windowSensor::windowSensor() : Sensor() {
	open_level = 0;
}

windowSensor::windowSensor(int ID, bool status, int sense_interval, int open_level) :
		Sensor (ID, status, sense_interval) {
	this->open_level = open_level;
}

void windowSensor::printData() const {
	cout << "Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval <<
		"-- open_level " << open_level << endl;
}

