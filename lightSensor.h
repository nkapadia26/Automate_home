// -- lightSensor.h ---

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class lightSensor : public Sensor {
private:
	double _luminence; // in lumens, say
	static const int _sense_interval = 5; // in minutes
public:
	lightSensor();
	lightSensor(int ID, bool status, double luminence);
	double getLuminence();
	void setLuminence(double luminence);
	void printData() const;
	friend class Parser;
	friend class Env;
};

#endif
