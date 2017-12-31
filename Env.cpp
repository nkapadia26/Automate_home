// --- Env.cpp ---
/*
We consider a 2D grid of rooms in the single-storey house.
Each room having the same five sensors -- read from the sensor_readings.txt file by Parser class.
Five 2D dynamic arrays used to store the sensor readings -- each for the corresponding class of sensor.
*/
#include <stdlib.h>
#include "Env.h"
using namespace std;

//The class constructor, although unusually long, allocates the object-variables 
Env::Env() {
	_grid_size_x = 5;
	_grid_size_y = 5;
	_curr_time = 0;
        _temperature_readings = new tempSensor*[_grid_size_x];
        _luminence_readings = new lightSensor*[_grid_size_x];
        _door_readings = new doorSensor*[_grid_size_x];
        _window_readings = new windowSensor*[_grid_size_x];
        _fire_readings = new fireSensor*[_grid_size_x];
        _occupancy_readings = new occupancySensor*[_grid_size_x];
	for(int i = 0; i < _grid_size_x; i++) {
            _temperature_readings[i] = new tempSensor[_grid_size_y];
            _luminence_readings[i] = new lightSensor[_grid_size_y];
            _window_readings[i] = new windowSensor[_grid_size_y];
            _door_readings[i] = new doorSensor[_grid_size_y];
            _fire_readings[i] = new fireSensor[_grid_size_y];
	    _occupancy_readings[i] = new occupancySensor[_grid_size_y];
        }
}
/*
Env::~Env() {
     // cout << "Env destructor: deleting the allocated arrays " << endl;
      for(int i = 0; i < grid_size_x; i++)
        {
                delete [] temperature_readings[grid_size_x];
                delete [] luminence_readings[grid_size_x];
                delete [] window_readings[grid_size_x];
                delete [] door_readings[grid_size_x];
                delete [] fire_readings[grid_size_x];
		delete [] occupancy_readings[grid_size_x];
        }
        delete [] temperature_readings;
        delete [] luminence_readings;
        delete [] window_readings;
        delete [] door_readings;
        delete [] fire_readings;
	delete [] fire_readings;

}
*/
tempSensor Env::getTempData(int x_coord, int y_coord) {
        return _temperature_readings[x_coord][y_coord];
}

lightSensor Env::getLightData(int x_coord, int y_coord) {
        return _luminence_readings[x_coord][y_coord];
}

doorSensor Env::getDoorData(int x_coord, int y_coord) {
        return _door_readings[x_coord][y_coord];
}

windowSensor Env::getWindowData(int x_coord, int y_coord) {
        return _window_readings[x_coord][y_coord];
}

fireSensor Env::getFireData(int x_coord, int y_coord) {
        return _fire_readings[x_coord][y_coord];
}

occupancySensor Env::getOccData(int x_coord, int y_coord) {
        return _occupancy_readings[x_coord][y_coord];
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
	_fire_readings[x_coord][y_coord].setTrigger(triggered);
}
void Env::setSunlight(double sunlight) {
	_sunlight = sunlight;
}

void Env::setOutsideTemp(double outside_temperature) {
	_outside_temperature = outside_temperature;
}

void Env::setTempData(int x_coord, int y_coord, double temperature) {
	_temperature_readings[x_coord][y_coord].setTemp(temperature);
}

void Env::setLightData(int x_coord, int y_coord, double luminence) {
	_luminence_readings[x_coord][y_coord].setLuminence(luminence);
}

void Env::setDoorData(int x_coord, int y_coord, bool locked) {
	_door_readings[x_coord][y_coord].setDoor(locked);
}

void Env::setWindowData(int x_coord, int y_coord, int open_level) {
	_window_readings[x_coord][y_coord].setOpenLevel(open_level);
}

void Env::setBlindData(int x_coord, int y_coord, int blind_level) {
        _window_readings[x_coord][y_coord].setBlindLevel(blind_level);
}

void Env::setOccData(int x_coord, int y_coord, bool occupied) {
	_occupancy_readings[x_coord][y_coord].setOccupancy(occupied);
}

void Env::setTime(unsigned int time) {
	_curr_time = time;
}



		
