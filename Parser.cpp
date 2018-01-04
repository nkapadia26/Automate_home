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
void Parser::readEnv() {
	string reading_type;
	ifstream input_file;
	input_file.open("sensor_readings.txt");
	int temp_int1, temp_int2, temp_int3, temp_int4, coord_x, coord_y;
	bool temp_bool1, temp_bool2;
	double temp_double;
	
	input_file >> _env->_grid_size_x >> _env->_grid_size_y; // reading in the 2D grid size
	_env->allocateEnv(_env->_grid_size_x, _env->_grid_size_y); 
	input_file >> _env->_outside_temperature >> _env->_sunlight;	
	while (input_file) { 
		input_file >> coord_x >> coord_y;
		input_file >> reading_type;
		if (!input_file) {
			break;
		}
		if (reading_type.compare("Temperature_Reading:") == 0) {
			input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;
			_env->_env_array[coord_x][coord_y]._temperature_reading._ID = temp_int1;
			_env->_env_array[coord_x][coord_y]._temperature_reading._status = temp_bool1;
			_env->_env_array[coord_x][coord_y]._temperature_reading._temperature = temp_double;
//			_env->_env_array[coord_x][coord_y]._temperature_reading.printData();
		}
		else if (reading_type.compare("Luminence_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;	
			_env->_env_array[coord_x][coord_y]._luminence_reading._ID = temp_int1;
                        _env->_env_array[coord_x][coord_y]._luminence_reading._status = temp_bool1;
                        _env->_env_array[coord_x][coord_y]._luminence_reading._luminence = temp_double;
  //                      _env->_env_array[coord_x][coord_y]._luminence_reading.printData();
                }
		else if (reading_type.compare("Fire_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			_env->_env_array[coord_x][coord_y]._fire_reading._ID = temp_int1;
                        _env->_env_array[coord_x][coord_y]._fire_reading._status = temp_bool1;
                        _env->_env_array[coord_x][coord_y]._fire_reading._triggered = temp_bool2;
    //                    _env_array[coord_x][coord_y]._fire_reading.printData();
                }
		else if (reading_type.compare("Door_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
			_env->_env_array[coord_x][coord_y]._door_reading._ID = temp_int1;
                        _env->_env_array[coord_x][coord_y]._door_reading._status = temp_bool1;
                        _env->_env_array[coord_x][coord_y]._door_reading._locked = temp_bool2;
      //                  _env_array[coord_x][coord_y]._door_reading.printData();
                }
		else if (reading_type.compare("Window_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_int3 >> temp_int4;
			_env->_env_array[coord_x][coord_y]._window_reading._ID = temp_int1;
                        _env->_env_array[coord_x][coord_y]._window_reading._status = temp_bool1;
                        _env->_env_array[coord_x][coord_y]._window_reading._open_level = temp_int3;
                        _env->_env_array[coord_x][coord_y]._window_reading._blind_level = temp_int4;
        //                _env_array[coord_x][coord_y]._window_reading.printData();
                }
		else if (reading_type.compare("Occupancy_Reading:") == 0) {
                         input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
                         _env->_env_array[coord_x][coord_y]._occupancy_reading._ID = temp_int1;
                         _env->_env_array[coord_x][coord_y]._occupancy_reading._status = temp_bool1;
                         _env->_env_array[coord_x][coord_y]._occupancy_reading._occupied = temp_bool2;
          //              _env_array[coord_x][coord_y]._occupancy_reading.printData();
                 }
		else {
			cout << "ERROR: Type of sensor reading not recognized" << endl;
			exit(1);
		}
		
	}
	input_file.close();

}



