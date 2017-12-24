// --- occupancySensor.h ---

#ifndef OCCSENSOR_H_
#define OCCSENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class occupancySensor : public Sensor {
private:
        bool occupied;
	// NO sense_interval -- event based invocation
public:
        occupancySensor();
        occupancySensor(int ID, bool status, bool occupied);
        void printData() const;
	friend class Parser;
	friend class Env;
};

#endif

