// --- Env.cpp ---
/*
We consider a 2D grid of rooms in the single-storey house.
Each room having the same five sensors -- read from the sensor_readings.txt file by Parser class.
Five 2D dynamic arrays used to store the sensor readings -- each for the corresponding class of sensor.
*/
#include <stdlib.h>
#include "Env.h"
#include <vector>
using namespace std;

//The class constructor, although unusually long, allocates the object-variables 
Env::Env() {
	_curr_time = 0;
}
void Env::allocateEnv(int grid_size_x, int grid_size_y) {
	_grid_size_x = grid_size_x;
	_grid_size_y = grid_size_y;
/*	vector <envElement> *p1;
	p1 = _env_array.get_allocator().allocate(grid_size_x);
	vector <envElement> vec(grid_size_y); 	
//	vector <envElement> *vec_ptr = new vector<envElement>(grid_size_y); 
        for (int i=0; i<grid_size_x; i++)
	        _env_array.get_allocator().construct(&p1[i],vec);
*/
        _env_array = new envElement*[_grid_size_x];
	for(int i = 0; i < _grid_size_x; i++) {
            _env_array[i] = new envElement[_grid_size_y];
        }
}
/*
Env::~Env() {
     // cout << "Env destructor: deleting the allocated arrays " << endl;
      for(int i = 0; i < grid_size_x; i++)
        {
                delete [] _env_array[grid_size_x];
        }
        delete [] _env_array;
}
*/
tempSensor Env::getTempData(int x_coord, int y_coord) {
        return _env_array[x_coord][y_coord].getTempElement();
}

lightSensor Env::getLightData(int x_coord, int y_coord) {
        return _env_array[x_coord][y_coord].getLightElement();
}

doorSensor Env::getDoorData(int x_coord, int y_coord) {
        return _env_array[x_coord][y_coord].getDoorElement();
}

windowSensor Env::getWindowData(int x_coord, int y_coord) {
        return _env_array[x_coord][y_coord].getWindowElement();
}

fireSensor Env::getFireData(int x_coord, int y_coord) {
        return _env_array[x_coord][y_coord].getFireElement();
}

occupancySensor Env::getOccData(int x_coord, int y_coord) {
        return _env_array[x_coord][y_coord].getOccElement();
}

pair<int, int> Env::getGridSize() {
        return make_pair(_grid_size_x, _grid_size_y);
}

double Env::getSunlight() {
	return _sunlight;
}

double Env::getOutsideTemp() {
	return _outside_temperature;
}

unsigned int Env::getTime() {
	return _curr_time;
}

void Env::setFireData(int x_coord, int y_coord, bool triggered) {
	_env_array[x_coord][y_coord].setFireElement(triggered);
}
void Env::setSunlight(double sunlight) {
	_sunlight = sunlight;
}

void Env::setOutsideTemp(double outside_temperature) {
	_outside_temperature = outside_temperature;
}

void Env::setTempData(int x_coord, int y_coord, double temperature) {
	_env_array[x_coord][y_coord].setTempElement(temperature);
}

void Env::setLightData(int x_coord, int y_coord, double luminence) {
	_env_array[x_coord][y_coord].setLightElement(luminence);
}

void Env::setDoorData(int x_coord, int y_coord, bool locked) {
	_env_array[x_coord][y_coord].setDoorElement(locked);
}

void Env::setWindowData(int x_coord, int y_coord, int open_level) {
	_env_array[x_coord][y_coord].setWindowElement(open_level);
}

void Env::setBlindData(int x_coord, int y_coord, int blind_level) {
        _env_array[x_coord][y_coord].setBlindElement(blind_level);
}

void Env::setOccData(int x_coord, int y_coord, bool occupied) {
	_env_array[x_coord][y_coord].setOccElement(occupied);
}

void Env::setTime(unsigned int time) {
	_curr_time = time;
}



		
