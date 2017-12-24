// --- occupancySensor.cpp ---

#include <iostream>
#include "occupancySensor.h"

using namespace std;

occupancySensor::occupancySensor() : Sensor() {
       occupied = 0;
}

occupancySensor::occupancySensor(int ID, bool status, bool occupied) :
                Sensor(ID, status) {
        this->occupied = occupied;
}

void occupancySensor::printData() const {
        cout << "Occupancy Sensor Data -- " << "ID: " << ID << ", STATUS: " << status <<
                " -- occupied: " << occupied << endl;
}

