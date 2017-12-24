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
#include <utility>
using namespace std;

Parser::Parser() {};
Env Parser::readFile() {
	string reading_type;
	ifstream input_file;
	input_file.open("sensor_readings.txt");
	int temp_int1, temp_int2, temp_int3, coord_x, coord_y;
	bool temp_bool1, temp_bool2;
	double temp_double;
	
	input_file >> temp_int1 >> temp_int2; // reading in the 2D grid size
	Env env(temp_int1, temp_int2);	
 	input_file >> env.outside_temperature >> env.sunlight;	
	while (input_file) { 
		input_file >> coord_x >> coord_y;
		input_file >> reading_type;
		if (!input_file) {
			break;
		}
		if (reading_type.compare("Temperature_Reading:") == 0) {
			input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;
			env.temperature_readings[coord_x][coord_y].ID = temp_int1;
			env.temperature_readings[coord_x][coord_y].status = temp_bool1;
			//env.temperature_readings[coord_x][coord_y].sense_interval = temp_int2; 
			env.temperature_readings[coord_x][coord_y].temperature = temp_double;
			env.temperature_readings[coord_x][coord_y].printData();
		}
		else if (reading_type.compare("Luminence_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;	
			env.luminence_readings[coord_x][coord_y].ID = temp_int1;
                        env.luminence_readings[coord_x][coord_y].status = temp_bool1;
                       // env.luminence_readings[coord_x][coord_y].sense_interval = temp_int2;
                        env.luminence_readings[coord_x][coord_y].luminence = temp_double;
                        env.luminence_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Fire_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			env.fire_readings[coord_x][coord_y].ID = temp_int1;
                        env.fire_readings[coord_x][coord_y].status = temp_bool1;
                        //env.fire_readings[coord_x][coord_y].sense_interval = temp_int2;
                        env.fire_readings[coord_x][coord_y].triggered = temp_bool2;
                        env.fire_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Door_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			env.door_readings[coord_x][coord_y].ID = temp_int1;
                        env.door_readings[coord_x][coord_y].status = temp_bool1;
                       // env.door_readings[coord_x][coord_y].sense_interval = temp_int2;
                        env.door_readings[coord_x][coord_y].locked = temp_bool2;
                        env.door_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Window_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_int3;
			env.window_readings[coord_x][coord_y].ID = temp_int1;
                        env.window_readings[coord_x][coord_y].status = temp_bool1;
                        //env.window_readings[coord_x][coord_y].sense_interval = temp_int2;
                        env.window_readings[coord_x][coord_y].open_level = temp_int3;
                        env.window_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Occupancy_Reading:") == 0) {
                         input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
                         env.occupancy_readings[coord_x][coord_y].ID = temp_int1;
                         env.occupancy_readings[coord_x][coord_y].status = temp_bool1;
                         env.occupancy_readings[coord_x][coord_y].occupied = temp_bool2;
                         env.occupancy_readings[coord_x][coord_y].printData();
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
	return env;
}



