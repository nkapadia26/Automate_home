// --- Sensor.cpp ---

#include <iostream>
#include "Sensor.h"

using namespace std;

Sensor::Sensor() {
	ID = 0;
	status = 1;
	sense_interval = 10;
}
Sensor::Sensor(int ID, bool status, int sense_interval) {
	this->ID = ID;
	this->status = status;
	this->sense_interval = sense_interval;
}
void Sensor::getData() const {
	cout << "Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval << endl;
}
