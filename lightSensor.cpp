// --- lightSensor.cpp ---

#include <iostream>
#include "lightSensor.h"

using namespace std;

lightSensor::lightSensor() : Sensor() {
	luminence = 10.0;
}

lightSensor::lightSensor(int ID, bool status, int sense_interval, double luminence1) :
                Sensor(ID, status, sense_interval) {
        luminence = luminence1;
}

void lightSensor::printData() const {
       cout << "Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval <<
		" -- luminence: " << luminence << endl;
}

