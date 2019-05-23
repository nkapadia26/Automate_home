// --- layoutParser.cpp ---
/*
We consider a 2D grid of rooms in the single-storey house.
Each room having the same five sensors -- read from the sensor_readings.txt file.
Five 2D dynamic arrays used to store the sensor readings -- each for the corresponding class of sensor.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "layoutParser.h"
#include "Env.h"
#include <utility>
using namespace std;

layoutParser::layoutParser(Env* env):Parser(env) {}

void layoutParser::readLayout() {
	string word;
	ifstream input_file;
	input_file.open("layout_coords.txt");
	int temp_int, coord_x, coord_y, leader_x, leader_y;
	
	while (input_file) { 
		input_file >> word;
		if (word.compare("cluster:") != 0) {
			cout << "layout text file is faulty " << endl;
			exit(1); 
		}
		input_file >> temp_int; // size of the cluster
		for (int i=0; i<temp_int; i++) { // first tile on the cluster is the leader
			input_file >> coord_x >> coord_y;
			if (i==0) {
				_env->_env_array[coord_x][coord_y].setRoomValidity(1);
				leader_x = coord_x;
				leader_y = coord_y;
			}
			else {
				_env->_env_array[coord_x][coord_y].setRoomValidity(0);
				_env->_env_array[coord_x][coord_y].setLeader(leader_x,leader_y);
			}
				
		}
	}
	input_file.close();
}



