// --- Env.h ---
// Tracks current environment (room-temperature, luminence etc.) variables
// ---
// For now, lets assume that all sensors are always up, and change in env-variables will result in immediate change in environment.
// So, a common set of variables for sensor-readings and current status of environment will suffice.
// And, controller-actions result in direct impact on sensor readings (e.g. forceDoor action will result in doorSensor.locked = 1)
// ---
#ifndef ENV_H_
#define ENV_H_

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

class Env {
private:
        // variables to store the 2D grid of sensor readings
        tempSensor** temperature_readings;
        lightSensor** luminence_readings;
        doorSensor** door_readings;
        windowSensor** window_readings;
        fireSensor** fire_readings;
	occupancySensor** occupancy_readings;
        int grid_size_x;
        int grid_size_y;
	double outside_temperature; // in F
	double sunlight; // in terms of luminence
	unsigned int curr_time; //-- in minutes -- simulation starts at 0
public:
        Env(int grid_size_x, int grid_size_y);
        pair<int, int> getGridSize();
	double getSunlight();
	double getOutsideTemp();
        tempSensor getTempData(int x_coord, int y_coord);
        lightSensor getLightData(int x_coord, int y_coord);
        doorSensor getDoorData(int x_coord, int y_coord);
        windowSensor getWindowData(int x_coord, int y_coord);
        fireSensor getFireData(int x_coord, int y_coord);
	occupancySensor getOccData(int x_coord, int y_coord);
	unsigned int getTime();
	friend class Parser;
	friend class Controller;
};

#endif

