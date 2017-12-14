// --- Sensor.h ---

#ifndef SENSOR_H_
#define SENSOR_H_

#include <iostream>
using namespace std;

class Sensor {
protected:
	int ID;
	bool status; // up: 1  OR  down: 0
	int sense_interval; // in seconds
public:
	Sensor();
	Sensor(int ID, bool status, int sense_interval);
	void getData() const;
	// parser method -- virtual ??
	
};

#endif
