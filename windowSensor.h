// --- windowSensor.h ---

#ifndef WINDOWSENSOR_H
#define WINDOWSENSOR_H

#include <iostream>
#include "Sensor.h"
using namespace std;

class windowSensor : public Sensor {
private:
	int _open_level; // 0 is closed .. 5 is fully open
	int _blind_level; // 0 is closed .. 5 is fully open
	static const int _sense_interval = 5; // in minutes -- 300 secs??
public:
	windowSensor();
	windowSensor(int ID, bool status, int open_level, int blind_level);
	void setOpenLevel(int open_level);
	void setBlindLevel(int blind_level);
	int getBlindLevel();
	int getOpenLevel();
	void printData() const;
	friend class Parser;
	friend class Env;	
};

#endif
