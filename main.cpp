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
	cout << "Size of the home is: " << p1.get_grid_size().first << " X " << p1.get_grid_size().second << " rooms" << endl;
 
	tempSensor ts1 = p1.getTempData(0, 0);
	ts1.printData();
	lightSensor ls1 = p1.getLightData(0,0);
	ls1.printData();
	doorSensor ds1 = p1.getDoorData(0, 0);
        ts1.printData();
        windowSensor ws1 = p1.getWindowData(0,0);
        ws1.printData();
	fireSensor fs1 = p1.getFireData(0,0);
	fs1.printData();

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
