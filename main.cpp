// --- main.cpp ---

#include <iostream>
#include "Sensor.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
//#include "doorSensor.h"
//#include "fireSensor.h"

using namespace std;

int main() {
	Sensor s1;
	Sensor s2(1, 1, 100);
	s1.getData();
	s2.getData();
	
	tempSensor ts1(2, 1, 100, 70.0);
	ts1.getData();
	cout << "temperature sensed: " << ts1.getTemp() << endl;	

	lightSensor ls1(3, 1, 50, 30.3);
	ls1.getData();
	cout << "light reading: " << ls1.getLight() << endl;	

	windowSensor ws1(4, 1, 60, 3);
        ws1.getData();
        cout << "window open-level: " << ws1.getLevel() << endl;	

	return 0;
} 
