// --- Sensor.cpp ---

#include <iostream>
#include "Sensor.h"

using namespace std;

Sensor::Sensor() {
	_ID = 0;
	_status = 1;
}
Sensor::Sensor(int ID, bool status) {
	_ID = ID;
	_status = status;
}

