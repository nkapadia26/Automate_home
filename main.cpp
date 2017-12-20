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
	
	cout << endl << endl;
	tempSensor ts2(2, 1, 100, 70.0);
	ts2.printData();
	
	lightSensor ls2(3, 1, 50, 30.3);
	ls2.printData();
	
	windowSensor ws2(4, 1, 60, 3);
        ws2.printData();

	doorSensor ds2; //(5, 1, 120, 1);
	ds2.printData();

	fireSensor fs2;
	fs2.printData();        

	return 0;
} 
