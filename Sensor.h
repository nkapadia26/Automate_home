// --- Sensor.h ---

#ifndef SENSOR_H_
#define SENSOR_H_

#include <iostream>
using namespace std;

class Sensor {
protected:
	int _ID;
	bool _status; // up: 1  OR  down: 0
public:
	Sensor();
	Sensor(int ID, bool status);
	virtual void printData() const = 0;
	friend class Parser;
        friend class Env;	
};

#endif
