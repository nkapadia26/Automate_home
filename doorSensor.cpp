// --- doorSensor.cpp ---

#include <iostream>
#include "doorSensor.h"

using namespace std;

doorSensor::doorSensor() : Sensor() {
	locked = 0;
}
doorSensor::doorSensor(int ID, bool status, bool locked) :
                Sensor (ID, status) {
        this->locked = locked;
}

void doorSensor::printData() const {
	cout << "Door Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval <<
                " -- locked: " << locked <<  endl;
}

