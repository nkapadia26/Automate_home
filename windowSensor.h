// --- windowSensor.h ---

#ifndef WINDOWSENSOR_H
#define WINDOWSENSOR_H

#include <iostream>
#include "Sensor.h"
using namespace std;

class windowSensor : public Sensor {
private:
	int open_level; // 0 is closed .. 5 is fully open
	int blind_level; // 0 is closed .. 5 is fully open
	static const int sense_interval = 5; // in minutes -- 300 secs??
public:
	windowSensor();
	windowSensor(int ID, bool status, int open_level, int blind_level);
	void printData() const;
	friend class Parser;
	friend class Env;	
};

#endif
