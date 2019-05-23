// --- tempSensor.cpp ---

#include <iostream>
#include "tempSensor.h"

using namespace std;

tempSensor::tempSensor() : Sensor() {
	_temperature = 70.0;
}

tempSensor::tempSensor(int ID, bool status, double temperature1) : 
        	Sensor(ID, status) {
	_temperature = temperature1;
}

void tempSensor::setTemp(double temp) { _temperature = temp; }
double tempSensor::getTemp() { return _temperature; }
void tempSensor::printData() const {
        cout << "Temperature Sensor Data -- " << "ID: " << _ID << ", STATUS: " << _status << ", SenseInterval: " << _sense_interval <<
		" -- temperature " << _temperature << endl;
}


