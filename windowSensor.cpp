// --- windowSensor.cpp ---

#include <iostream>
#include "windowSensor.h"

using namespace std;

windowSensor::windowSensor() : Sensor() {
	_open_level = 0;
	_blind_level = 0;
}

windowSensor::windowSensor(int ID, bool status, int open_level, int blind_level) :
		Sensor (ID, status) {
	_open_level = open_level;
	_blind_level = blind_level;
}

void windowSensor::setOpenLevel(int open_level) { _open_level = open_level; }
void windowSensor::setBlindLevel(int blind_level)  { _blind_level = blind_level; }
int windowSensor::getOpenLevel() { return _open_level; }
int windowSensor::getBlindLevel() { return _blind_level; }

void windowSensor::printData() const {
	cout << "Window Sensor Data -- " << "ID: " << _ID << ", STATUS: " << _status << ", SenseInterval: " << _sense_interval <<
		"-- open_level " << _open_level << ", blind_level " << _blind_level << endl;
}

