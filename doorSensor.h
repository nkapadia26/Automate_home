// --- doorSensor.h ---

#ifndef DOORSENSOR_H
#define DOORSENSOR_H

#include <iostream>
#include "Sensor.h"
using namespace std;

class doorSensor : public Sensor {
private:
	bool _locked; // 0 is unlocked .. 1 is locked
	static const int _sense_interval = 5; // in minutes
public:
        doorSensor();
	doorSensor(int ID, bool status, bool locked);
	bool getDoor();
	void setDoor(bool locked);
        void printData() const;
	friend class envParser;
        friend class layoutParser;
//	friend class Parser;
	friend class Env;
};

#endif

