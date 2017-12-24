// --- doorSensor.h ---

#ifndef DOORSENSOR_H
#define DOORSENSOR_H

#include <iostream>
#include "Sensor.h"
using namespace std;

class doorSensor : public Sensor {
private:
	bool locked; // 0 is unlocked .. 1 is locked
	static const int sense_interval = 5; // in minutes
public:
        doorSensor();
	doorSensor(int ID, bool status, bool locked);
        void printData() const;
	friend class Parser;
	friend class Env;
};

#endif

