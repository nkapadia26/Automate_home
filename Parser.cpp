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

Parser::Parser(Env* env) {
	_env = env;
}
void Parser::readFile() {
	string reading_type;
	ifstream input_file;
	input_file.open("sensor_readings.txt");
	int temp_int1, temp_int2, temp_int3, temp_int4, coord_x, coord_y;
	bool temp_bool1, temp_bool2;
	double temp_double;
	
//	input_file >> _env->_grid_size_x >> _env->_grid_size_y; // reading in the 2D grid size
 	input_file >> _env->_outside_temperature >> _env->_sunlight;	
	while (input_file) { 
		input_file >> coord_x >> coord_y;
		input_file >> reading_type;
		if (!input_file) {
			break;
		}
		if (reading_type.compare("Temperature_Reading:") == 0) {
			input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;
			_env->_temperature_readings[coord_x][coord_y]._ID = temp_int1;
			_env->_temperature_readings[coord_x][coord_y]._status = temp_bool1;
			_env->_temperature_readings[coord_x][coord_y]._temperature = temp_double;
//			_env->_temperature_readings[coord_x][coord_y].printData();
		}
		else if (reading_type.compare("Luminence_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;	
			_env->_luminence_readings[coord_x][coord_y]._ID = temp_int1;
                        _env->_luminence_readings[coord_x][coord_y]._status = temp_bool1;
                        _env->_luminence_readings[coord_x][coord_y]._luminence = temp_double;
  //                      _env->_luminence_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Fire_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			_env->_fire_readings[coord_x][coord_y]._ID = temp_int1;
                        _env->_fire_readings[coord_x][coord_y]._status = temp_bool1;
                        _env->_fire_readings[coord_x][coord_y]._triggered = temp_bool2;
    //                    _env->_fire_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Door_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			_env->_door_readings[coord_x][coord_y]._ID = temp_int1;
                        _env->_door_readings[coord_x][coord_y]._status = temp_bool1;
                        _env->_door_readings[coord_x][coord_y]._locked = temp_bool2;
      //                  _env->_door_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Window_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_int3 >> temp_int4;
			_env->_window_readings[coord_x][coord_y]._ID = temp_int1;
                        _env->_window_readings[coord_x][coord_y]._status = temp_bool1;
                        _env->_window_readings[coord_x][coord_y]._open_level = temp_int3;
                        _env->_window_readings[coord_x][coord_y]._blind_level = temp_int4;
        //                _env->_window_readings[coord_x][coord_y].printData();
                }
		else if (reading_type.compare("Occupancy_Reading:") == 0) {
                         input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
                         _env->_occupancy_readings[coord_x][coord_y]._ID = temp_int1;
                         _env->_occupancy_readings[coord_x][coord_y]._status = temp_bool1;
                         _env->_occupancy_readings[coord_x][coord_y]._occupied = temp_bool2;
          //               _env->_occupancy_readings[coord_x][coord_y].printData();
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
}



