// -- tempSensor.h ---

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class tempSensor : public Sensor {
private:
	double _temperature;
	static const double _lowest_legal_temp = -70.0;
	static const double _highest_legal_temp = 130.0;
	static const int _sense_interval = 5; // in minutes
public:
	tempSensor();
	tempSensor(int ID, bool status, double temperature);
	void setTemp(double temp);
	double getTemp();
	void printData() const;
	friend class Parser;	
	friend class Env;
};

#endif
