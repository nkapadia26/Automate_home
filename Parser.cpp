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
#include <sstream>
#include "Parser.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
#include "doorSensor.h"
#include "fireSensor.h"

using namespace std;

Parser::Parser() {};

void Parser::parse_file() {
	string reading_type;
	ifstream input_file;
	input_file.open("sensor_readings.txt");
	int temp_int1, temp_int2, temp_int3, coord_x, coord_y;
	bool temp_bool1, temp_bool2;
	double temp_double;
	
	input_file >> grid_size_x >> grid_size_y; // reading in the 2D grid size
	temperature_readings = new tempSensor*[grid_size_x];
	luminence_readings = new lightSensor*[grid_size_x];
	door_readings = new doorSensor*[grid_size_x];
	window_readings = new windowSensor*[grid_size_x];
	fire_readings = new fireSensor*[grid_size_x];	
	for(int i = 0; i < grid_size_x; i++) {
	    temperature_readings[i] = new tempSensor[grid_size_y];
	    luminence_readings[i] = new lightSensor[grid_size_y];
	    window_readings[i] = new windowSensor[grid_size_y];
	    door_readings[i] = new doorSensor[grid_size_y];
	    fire_readings[i] = new fireSensor[grid_size_y]; 
	}

	while (input_file) { 
		input_file >> coord_x >> coord_y;
		input_file >> reading_type;
		if (!input_file){
			break;
		}
		if (reading_type.compare("Temperature_Reading:") == 0) {
			input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;
			temperature_readings[coord_x][coord_y].ID = temp_int1;
			temperature_readings[coord_x][coord_y].status = temp_bool1;
			temperature_readings[coord_x][coord_y].sense_interval = temp_int2; 
			temperature_readings[coord_x][coord_y].temperature = temp_double;
			temperature_readings[coord_x][coord_y].printData();
		}
		else if (reading_type.compare("Luminence_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;	
			luminence_readings[coord_x][coord_y].ID = temp_int1;
                        luminence_readings[coord_x][coord_y].status = temp_bool1;
                        luminence_readings[coord_x][coord_y].sense_interval = temp_int2;
                        luminence_readings[coord_x][coord_y].luminence = temp_double;
                        luminence_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Fire_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			fire_readings[coord_x][coord_y].ID = temp_int1;
                        fire_readings[coord_x][coord_y].status = temp_bool1;
                        fire_readings[coord_x][coord_y].sense_interval = temp_int2;
                        fire_readings[coord_x][coord_y].triggered = temp_bool2;
                        fire_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Door_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			door_readings[coord_x][coord_y].ID = temp_int1;
                        door_readings[coord_x][coord_y].status = temp_bool1;
                        door_readings[coord_x][coord_y].sense_interval = temp_int2;
                        door_readings[coord_x][coord_y].locked = temp_bool2;
                        door_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Window_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_int3;
			window_readings[coord_x][coord_y].ID = temp_int1;
                        window_readings[coord_x][coord_y].status = temp_bool1;
                        window_readings[coord_x][coord_y].sense_interval = temp_int2;
                        window_readings[coord_x][coord_y].open_level = temp_int3;
                        window_readings[coord_x][coord_y].printData();
                }
		else {
			cout << "ERROR: Type of sensor reading not recognized" << endl;
			exit(1);
		}
		
	}
	input_file.close();

/*	for(int i = 0; i < grid_size_x; i++) {
		for (int j = 0; j < grid_size_y; j++) {
			cout << temperature_readings[i][j].temperature << " ";
		} cout << endl;
	}
*/
	// deleting the allocated arrays		
	for(int i = 0; i < grid_size_x; i++)
	{
		delete [] temperature_readings[grid_size_x];
		delete [] luminence_readings[grid_size_x];
		delete [] window_readings[grid_size_x];
		delete [] door_readings[grid_size_x];
		delete [] fire_readings[grid_size_x];
	}
	delete [] temperature_readings;
	delete [] luminence_readings;
	delete [] window_readings;
	delete [] door_readings;
	delete [] fire_readings;
}

