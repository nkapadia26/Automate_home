// --- lightSensor.cpp ---

#include <iostream>
#include "lightSensor.h"

using namespace std;

lightSensor::lightSensor() : Sensor() {
	_luminence = 10.0;
}

lightSensor::lightSensor(int ID, bool status, double luminence1) :
                Sensor(ID, status) {
        _luminence = luminence1;
}

void lightSensor::setLuminence(double luminence) { _luminence = luminence; }

double lightSensor::getLuminence() { return _luminence; }

void lightSensor::printData() const {
       cout << "Light Sensor Data -- " << "ID: " << _ID << ", STATUS: " << _status << ", SenseInterval: " << _sense_interval <<
		" -- luminence: " << _luminence << endl;
}

