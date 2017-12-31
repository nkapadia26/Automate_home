// --- fireSensor.cpp ---

#include <iostream>
#include "fireSensor.h"

using namespace std;

fireSensor::fireSensor() : Sensor() {
       _triggered = 0;
}

fireSensor::fireSensor(int ID, bool status, bool triggered) :
                Sensor(ID, status) {
        _triggered = triggered;
}

bool fireSensor::getTrigger() {
	return _triggered;
}

void fireSensor::setTrigger(bool triggered) {
	_triggered = triggered;
}

void fireSensor::printData() const {
        cout << "Fire Sensor Data -- " << "ID: " << _ID << ", STATUS: " << _status << 
                " -- triggered: " << _triggered << endl;
}

