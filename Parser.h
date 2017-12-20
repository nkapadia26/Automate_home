// --- Parser.h ---

#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <fstream>
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
#include "doorSensor.h"
#include "fireSensor.h"
#include <utility>
#include <string>
using namespace std;

class Parser {
private:
	// variables to store the 2D grid of sensor readings
	tempSensor** temperature_readings;
	lightSensor** luminence_readings;
	doorSensor** door_readings;
	windowSensor** window_readings;
	fireSensor** fire_readings;
	int grid_size_x;
	int grid_size_y;

public:
	Parser();
	pair<int, int> get_grid_size();
	tempSensor getTempData(int x_coord, int y_coord);
	lightSensor getLightData(int x_coord, int y_coord);
	doorSensor getDoorData(int x_coord, int y_coord);
	windowSensor getWindowData(int x_coord, int y_coord);
	fireSensor getFireData(int x_coord, int y_coord);
}; 

#endif
