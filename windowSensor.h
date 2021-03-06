// --- windowSensor.h ---

#ifndef WINDOWSENSOR_H
#define WINDOWSENSOR_H

#include <iostream>
#include "Sensor.h"
using namespace std;

class windowSensor : public Sensor {
private:
	int open_level; // 0 is closed .. 5 is fully open
public:
	windowSensor();
	windowSensor(int ID, bool status, int sense_interval, int open_level);
	void printData() const;
	friend class Parser;
};

#endif
