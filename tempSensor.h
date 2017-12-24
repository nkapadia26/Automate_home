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
	static const int sense_interval = 5; // in minutes
public:
	tempSensor();
	tempSensor(int ID, bool status, double temperature);
	void printData() const;
	friend class Parser;	
	friend class Env;
};

#endif
