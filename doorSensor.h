// --- doorSensor.h ---

#ifndef DOORSENSOR_H
#define DOORSENSOR_H

#include <iostream>
#include "Sensor.h"
using namespace std;

class doorSensor : public Sensor {
private:
	bool locked; // 0 is unlocked .. 1 is locked
public:
        doorSensor();
	doorSensor(int ID, bool status, int sense_interval, bool locked);
        void printData() const;
};

#endif

