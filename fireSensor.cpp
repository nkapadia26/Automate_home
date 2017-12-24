// --- fireSensor.cpp ---

#include <iostream>
#include "fireSensor.h"

using namespace std;

fireSensor::fireSensor() : Sensor() {
       triggered = 0;
}

fireSensor::fireSensor(int ID, bool status, bool triggered) :
                Sensor(ID, status) {
        this->triggered = triggered;
}

void fireSensor::printData() const {
        cout << "Fire Sensor Data -- " << "ID: " << ID << ", STATUS: " << status << 
                " -- triggered: " << triggered << endl;
}

