// --- fireSensor.h ---

#ifndef FIRESENSOR_H_
#define FIRESENSOR_H_

#include <iostream>
#include "Sensor.h"
using namespace std;

class fireSensor : public Sensor {
private:
        bool triggered;
public:
        fireSensor();
        fireSensor(int ID, bool status, int sense_interval, bool triggered);
        void printData() const;

};

#endif

