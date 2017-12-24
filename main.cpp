// --- main.cpp ---

#include <iostream>
#include "Sensor.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
#include "doorSensor.h"
#include "fireSensor.h"
#include "occupancySensor.h"
#include "Parser.h"
#include "Env.h"

using namespace std;

int main() {
	Parser p1;
	Env env = p1.readFile();
	cout << "Size of the home is: " << env.getGridSize().first << " X " << env.getGridSize().second << " rooms" << endl;
	cout << "Outside Temperature: " << env.getOutsideTemp() << "  Sunlight level: " << env.getSunlight() << endl;
 
	tempSensor ts1 = env.getTempData(0, 0);
	ts1.printData();
	lightSensor ls1 = env.getLightData(0,0);
	ls1.printData();
	doorSensor ds1 = env.getDoorData(0, 0);
        ts1.printData();
        windowSensor ws1 = env.getWindowData(0,0);
        ws1.printData();
	fireSensor fs1 = env.getFireData(0,0);
	fs1.printData();
	occupancySensor os1 = env.getOccData(0,0);
	os1.printData();	

	cout << endl << endl;
	tempSensor ts2(2, 1, 70.0);
	ts2.printData();
	
	lightSensor ls2(3, 1, 30.3);
	ls2.printData();
	
	windowSensor ws2(4, 1, 3, 4);
        ws2.printData();

	doorSensor ds2; //(5, 1, 120, 1);
	ds2.printData();

	fireSensor fs2;
	fs2.printData();        

	return 0;
} 
