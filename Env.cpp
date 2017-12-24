// --- Env.cpp ---
/*
We consider a 2D grid of rooms in the single-storey house.
Each room having the same five sensors -- read from the sensor_readings.txt file by Parser class.
Five 2D dynamic arrays used to store the sensor readings -- each for the corresponding class of sensor.
*/
#include <stdlib.h>
#include "Parser.h"
using namespace std;

//The class constructor, although unusually long, allocates the object-variables 
Env::Env(int grid_size_x, int grid_size_y) {
	this->grid_size_x = grid_size_x;
	this->grid_size_y = grid_size_y;
        temperature_readings = new tempSensor*[grid_size_x];
        luminence_readings = new lightSensor*[grid_size_x];
        door_readings = new doorSensor*[grid_size_x];
        window_readings = new windowSensor*[grid_size_x];
        fire_readings = new fireSensor*[grid_size_x];
        occupancy_readings = new occupancySensor*[grid_size_x];
	for(int i = 0; i < grid_size_x; i++) {
            temperature_readings[i] = new tempSensor[grid_size_y];
            luminence_readings[i] = new lightSensor[grid_size_y];
            window_readings[i] = new windowSensor[grid_size_y];
            door_readings[i] = new doorSensor[grid_size_y];
            fire_readings[i] = new fireSensor[grid_size_y];
	    occupancy_readings[i] = new occupancySensor[grid_size_y];
        }

/*      for(int i = 0; i < grid_size_x; i++) {
                for (int j = 0; j < grid_size_y; j++) {
                        cout << temperature_readings[i][j].temperature << " ";
                } cout << endl;
        }
*/
        // deleting the allocated arrays                
/*      for(int i = 0; i < grid_size_x; i++)
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
*/
}

tempSensor Env::getTempData(int x_coord, int y_coord) {
        return temperature_readings[x_coord][y_coord];
}

lightSensor Env::getLightData(int x_coord, int y_coord) {
        return luminence_readings[x_coord][y_coord];
}

doorSensor Env::getDoorData(int x_coord, int y_coord) {
        return door_readings[x_coord][y_coord];
}

windowSensor Env::getWindowData(int x_coord, int y_coord) {
        return window_readings[x_coord][y_coord];
}

fireSensor Env::getFireData(int x_coord, int y_coord) {
        return fire_readings[x_coord][y_coord];
}

occupancySensor Env::getOccData(int x_coord, int y_coord) {
        return occupancy_readings[x_coord][y_coord];
}

pair<int, int> Env::getGridSize() {
        return make_pair(grid_size_x, grid_size_y);
}

double Env::getSunlight() {
	return sunlight;
}

double Env::getOutsideTemp() {
	return outside_temperature;
}

unsigned int Env::getTime() {
	return curr_time;
}
		
