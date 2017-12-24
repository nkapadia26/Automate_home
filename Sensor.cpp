// --- Sensor.cpp ---

#include <iostream>
#include "Sensor.h"

using namespace std;

Sensor::Sensor() {
	ID = 0;
	status = 1;
}
Sensor::Sensor(int ID, bool status) {
	this->ID = ID;
	this->status = status;
}

