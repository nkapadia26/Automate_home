// --- lightSensor.cpp ---

#include <iostream>
#include "lightSensor.h"

using namespace std;

lightSensor::lightSensor(int ID, bool status, int sense_interval, double luminence1) :
                Sensor(ID, status, sense_interval) {
        luminence = luminence1;
}

double lightSensor::getLight() const {
        return luminence;
}

