// --- main.cpp ---

#include <iostream>
#include "Sensor.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
#include "doorSensor.h"
#include "fireSensor.h"
#include "Parser.h"

using namespace std;

int main() {
	Parser p1;
	p1.parse_file();
	
/*	tempSensor ts1(2, 1, 100, 70.0);
	ts1.printData();
	
	lightSensor ls1(3, 1, 50, 30.3);
	ls1.printData();
	
	windowSensor ws1(4, 1, 60, 3);
        ws1.printData();

	doorSensor ds1; //(5, 1, 120, 1);
	ds1.printData();

	fireSensor fs1;
	fs1.printData();        
*/
	return 0;
} 
