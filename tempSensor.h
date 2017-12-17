// -- tempSensor.h ---

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class tempSensor : public Sensor {
private:
	double temperature;
	static const double lowest_legal_temp = -70.0;
	static const double highest_legal_temp = 130.0;
public:
	tempSensor();
	tempSensor(int ID, bool status, int sense_interval, double temperature);
	void printData() const;
	
};

#endif
