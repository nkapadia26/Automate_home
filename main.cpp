// --- main.cpp ---

#include <iostream>
/*
#include "Sensor.h"
#include "tempSensor.h"
#include "lightSensor.h"
#include "windowSensor.h"
#include "doorSensor.h"
#include "fireSensor.h"
#include "occupancySensor.h"
*/
#include "Parser.h"
#include "Env.h"
#include "Controller.h"
#include "userSettings.h"
#include "controllerGrid.h"
using namespace std;

void printStatus(int x_coord, int y_coord, Env* env, userSettings* us, controllerGrid* cg);

int main() {
	Env env;
	Parser p1(&env);
	p1.readEnv();
	cout << "Size of the home is: " << env.getGridSize().first << " X " << env.getGridSize().second << " rooms" << endl;
	cout << "Outside Temperature: " << env.getOutsideTemp() << "  Sunlight level: " << env.getSunlight() << endl;
 
	userSettings us1(env);
	us1.readUserSettings();
	
	int x = 1; int y = 2;
	controllerGrid cg(env.getGridSize().first, env.getGridSize().second, &env, &us1);
	cg.initializeGrid();
	printStatus(x, y, &env, &us1, &cg); cout << endl << " -- env, controller and userSettings BEFORE control-actions" << endl << endl;
	cg.converge();	
	printStatus(x, y, &env, &us1, &cg); cout << endl << " -- env, controller and userSettings AFTER control-actions "<< endl;

//	delete &env;	

	return 0;
} 

void printStatus(int x_coord, int y_coord, Env* env, userSettings* us, controllerGrid* cg) {
	cout << "user settings -- Luminence/Temperature " << us->getLuminence(x_coord, y_coord) << "/" << us->getTemperature(x_coord,y_coord) << endl;	
	cout << " Environment -- ";
	cout << endl << "Sunlight: " << env->getSunlight();
        cout << endl << "Outside Temperature: " << env->getOutsideTemp();
        cout << endl << "Temperature: " << env->getTempData(x_coord, y_coord).getTemp();
        cout << endl << "Luminence: " << env->getLightData(x_coord, y_coord).getLuminence() ;
        cout << endl << "Locked: " << env->getDoorData(x_coord, y_coord).getDoor();
        cout << endl << "Blind level: " << env->getWindowData(x_coord, y_coord).getBlindLevel();
        cout << endl << "Window Open Level: " << env->getWindowData(x_coord, y_coord).getOpenLevel();
        cout << endl << "Fire triggered: " << env->getFireData(x_coord, y_coord).getTrigger();
        cout << endl << "Occupied: " << env->getOccData(x_coord, y_coord).getOccupancy() << endl;

	cout << " Controller outputs -- " << endl;
	cout << "Heat level: " << cg->getElement(x_coord, y_coord).getHeatLevel() << endl;
	cout << "Lighting level: " << cg->getElement(x_coord, y_coord).getLightingLevel() << endl;
	cout << "Water ON: " << cg->getElement(x_coord, y_coord).getWaterOn() << endl;	
}
