// --- fireSensor.h ---

#ifndef FIRESENSOR_H_
#define FIRESENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class fireSensor : public Sensor {
private:
        bool triggered;
	// NO sense_interval -- event based invocation
public:
        fireSensor();
        fireSensor(int ID, bool status, bool triggered);
        void printData() const;
	friend class Parser;
	friend class Env;
};

#endif

