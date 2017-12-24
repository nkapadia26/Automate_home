// --- windowSensor.cpp ---

#include <iostream>
#include "windowSensor.h"

using namespace std;

windowSensor::windowSensor() : Sensor() {
	open_level = 0;
	blind_level = 0;
}

windowSensor::windowSensor(int ID, bool status, int open_level, int blind_level) :
		Sensor (ID, status) {
	this->open_level = open_level;
	this->blind_level = blind_level;
}

void windowSensor::printData() const {
	cout << "Window Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval <<
		"-- open_level " << open_level << ", blind_level " << blind_level << endl;
}

