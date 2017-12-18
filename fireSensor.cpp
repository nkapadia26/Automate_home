// --- fireSensor.cpp ---

#include <iostream>
#include "fireSensor.h"

using namespace std;

fireSensor::fireSensor() : Sensor() {
       triggered = 0;
}

fireSensor::fireSensor(int ID, bool status, int sense_interval, bool triggered) :
                Sensor(ID, status, sense_interval) {
        this->triggered = triggered;
}

void fireSensor::printData() const {
        cout << "Fire Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << ", SenseInterval: " << sense_interval <<
                " -- triggered: " << triggered << endl;
}

