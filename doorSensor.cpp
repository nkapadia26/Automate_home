// --- doorSensor.cpp ---

#include <iostream>
#include "doorSensor.h"

using namespace std;

doorSensor::doorSensor() : Sensor() {
	_locked = 0;
}
doorSensor::doorSensor(int ID, bool status, bool locked) :
                Sensor (ID, status) {
        _locked = locked;
}

void doorSensor::setDoor(bool locked) {
	_locked = locked;
}

bool doorSensor::getDoor() {
	return _locked;
}

void doorSensor::printData() const {
	cout << "Door Sensor Data -- " << "ID: " << _ID << ", STATUS: " << _status << ", SenseInterval: " << _sense_interval <<
                " -- locked: " << _locked <<  endl;
}

