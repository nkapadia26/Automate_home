// -- lightSensor.h ---

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class lightSensor : public Sensor {
private:
	double luminence; // in lumens, say
public:
	lightSensor(int ID, bool status, int sense_interval, double luminence);
	double getLight() const;
};

#endif
