// --- Parser.cpp ---

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
	int temp_int1, temp_int2, temp_int3;
	bool temp_bool1, temp_bool2;
	double temp_double;

	while (input_file) { 
		input_file >> reading_type;
		if (!input_file){
			break;
		}
		if (reading_type.compare("Temperature_Reading:") == 0) {
			input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;
			tempSensor ts1(temp_int1, temp_bool1, temp_int2, temp_double);
			ts1.printData();
		}
		else if (reading_type.compare("Luminence_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_double;
                        lightSensor ls1(temp_int1, temp_bool1, temp_int2, temp_double);
			ls1.printData();
                }
		else if (reading_type.compare("Fire_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
                        fireSensor fs1(temp_int1, temp_bool1, temp_int2, temp_bool2);
                        fs1.printData();
                }
		else if (reading_type.compare("Door_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_bool2;
                        doorSensor ds1(temp_int1, temp_bool1, temp_int2, temp_bool2);
			ds1.printData();
                }
		else if (reading_type.compare("Window_Sensor_Reading:") == 0) {
                        input_file >> temp_int1; input_file >> temp_bool1; input_file >> temp_int2; input_file >> temp_int3;
                        windowSensor ws1(temp_int1, temp_bool1, temp_int2, temp_int3);
                        ws1.printData();	
                }
		else {
			cout << "ERROR: Type of sensor reading not recognized" << endl;
			exit(1);
		}
		
	}
	input_file.close();
}

