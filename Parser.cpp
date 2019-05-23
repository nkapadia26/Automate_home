// --- Parser.cpp ---
/*
We consider a 2D grid of rooms in the single-storey house.
Each room having the same five sensors -- read from the sensor_readings.txt file.
Five 2D dynamic arrays used to store the sensor readings -- each for the corresponding class of sensor.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Parser.h"
#include "Env.h"
//#include <utility>
using namespace std;

Parser::Parser(Env* env) {
	_env = env;
}

