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
	windowSensor(int ID, bool status, int sense_interval, int open_level);
	int getLevel() const;
};

#endif
