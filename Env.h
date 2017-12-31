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
        tempSensor** _temperature_readings;
        lightSensor**_luminence_readings;
        doorSensor** _door_readings;
        windowSensor** _window_readings;
        fireSensor** _fire_readings;
	occupancySensor** _occupancy_readings;
        int _grid_size_x;
        int _grid_size_y;
	double _outside_temperature; // in F
	double _sunlight; // in terms of luminence
	unsigned int _curr_time; //-- in minutes -- simulation starts at 0
public:
//        Env(int grid_size_x, int grid_size_y);
	Env();
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

	void setSunlight(double);
        void setOutsideTemp(double);
        void setTempData(int x_coord, int y_coord, double);
        void setLightData(int x_coord, int y_coord, double);
        void setDoorData(int x_coord, int y_coord, bool);
        void setBlindData(int x_coord, int y_coord, int);
        void setWindowData(int x_coord, int y_coord, int);
        void setFireData(int x_coord, int y_coord, bool);
        void setOccData(int x_coord, int y_coord, bool);
        void setTime(unsigned int);

	friend class Parser;
	friend class Controller;
};

#endif

