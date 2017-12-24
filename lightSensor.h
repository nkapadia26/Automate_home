// -- lightSensor.h ---

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class lightSensor : public Sensor {
private:
	double luminence; // in lumens, say
	static const int sense_interval = 5; // in minutes
public:
	lightSensor();
	lightSensor(int ID, bool status, double luminence);
	void printData() const;
	friend class Parser;
	friend class Env;
};

#endif
