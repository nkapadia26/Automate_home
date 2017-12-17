// --- tempSensor.cpp ---

#include <iostream>
#include "tempSensor.h"

using namespace std;

tempSensor::tempSensor() : Sensor() {
	temperature = 70.0;
}

tempSensor::tempSensor(int ID, bool status, int sense_interval, double temperature1) : 
        	Sensor(ID, status, sense_interval) {
	temperature = temperature1;
}

void tempSensor::printData() const {
        cout << "Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval <<
		" -- temperature " << temperature << endl;
}


