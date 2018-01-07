// --- fireSensor.h ---

#ifndef FIRESENSOR_H_
#define FIRESENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class fireSensor : public Sensor {
private:
        bool _triggered;
	// NO sense_interval -- event based invocation
public:
        fireSensor();
        fireSensor(int ID, bool status, bool triggered);
        void printData() const;
	bool getTrigger();
	void setTrigger(bool triggered);
	friend class envParser;
        friend class layoutParser;
//	friend class Parser;
	friend class Env;
};

#endif

