// --- occupancySensor.cpp ---

#include <iostream>
#include "occupancySensor.h"

using namespace std;

occupancySensor::occupancySensor() : Sensor() {
       _occupied = 0;
}

occupancySensor::occupancySensor(int ID, bool status, bool occupied) :
                Sensor(ID, status) {
        _occupied = occupied;
}

void occupancySensor::setOccupancy(bool occupied) {
	_occupied = occupied;
}

bool occupancySensor::getOccupancy() {
	return _occupied;
}


void occupancySensor::printData() const {
        cout << "Occupancy Sensor Data -- " << "ID: " << _ID << ", STATUS: " << _status <<
                " -- occupied: " << _occupied << endl;
}

