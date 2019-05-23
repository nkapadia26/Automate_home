// --- main.cpp ---

#include <iostream>
#include "envParser.h"
#include "layoutParser.h"
#include "Env.h"
#include "Controller.h"
#include "userSettings.h"
#include "controllerGrid.h"
using namespace std;

void printStatus(int x_coord, int y_coord, Env* env, userSettings* us, controllerGrid* cg);

int main() {
	Env env;
	envParser p1(&env);
	p1.readEnv();
//	cout << "Size of the home is: " << env.getGridSize().first << " X " << env.getGridSize().second << " rooms" << endl;
	cout << "Outside Temperature: " << env.getOutsideTemp() << "  Sunlight level: " << env.getSunlight() << endl;

	layoutParser p2(&env);
	p2.readLayout();	
 
	userSettings us1(env);
	us1.readUserSettings();
	us1.printSettings();	
	int x = 1; int y = 2;
	controllerGrid cg(env.getGridSizes().first, env.getGridSizes().second, &env, &us1);
	cg.initializeGrid();
	cout << endl << " -- env, controller and userSettings BEFORE control-actions" << endl << endl;
	printStatus(x, y, &env, &us1, &cg); 
	cg.converge();	
	cout << endl << " -- env, controller and userSettings AFTER control-actions "<< endl;
	printStatus(x, y, &env, &us1, &cg); 
	cg.converge();

	// -- deallocation --
//	cg.~controllerGrid();
//	us1.~userSettings();
	env.deallocateEnv();

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
