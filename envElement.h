// --- envElement.h ---
// Tracks current environment (room-temperature, luminence etc.) variables
// ---
// For now, lets assume that all sensors are always up, and change in env-variables will result in immediate change in environment.
// So, a common set of variables for sensor-readings and current status of environment will suffice.
// And, controller-actions result in direct impact on sensor readings (e.g. forceDoor action will result in doorSensor.locked = 1)
// ---
#ifndef ENVELEMENT_H_
#define ENVELEMENT_H_

#include <iostream>
#include <fstream>
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
#include "doorSensor.h"
#include "fireSensor.h"
#include "occupancySensor.h"
#include <utility>
#include <string>
using namespace std;

class envElement {
private:
        // variables to store the 2D grid of sensor readings
        tempSensor _temperature_reading;
        lightSensor _luminence_reading;
        doorSensor _door_reading;
        windowSensor _window_reading;
        fireSensor _fire_reading;
	occupancySensor _occupancy_reading;      
public:
	envElement();
        tempSensor getTempElement();
        lightSensor getLightElement();
        doorSensor getDoorElement();
        windowSensor getWindowElement();
        fireSensor getFireElement();
	occupancySensor getOccElement();

        void setTempElement(double);
        void setLightElement(double);
        void setDoorElement(bool);
        void setBlindElement(int);
        void setWindowElement(int);
        void setFireElement(bool);
        void setOccElement(bool);

	friend class Parser;
//	friend class Controller;
};

#endif

