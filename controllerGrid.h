// --- controllerGrid.h ---

// Basically, holds the 2D array of Controller-class objects. Also, methods governing control-actions that consider neighborhood will go here.

#ifndef CONTROLLERGRID_H_
#define CONTROLLERGRID_H_

#include <iostream>

class Env;
class Controller;

class controllerGrid {
private:
	Controller** _control_grid;
	Env* _env;
	userSettings* _us;
public:
	controllerGrid(int x_dim, int y_dim, Env* env, userSettings* us);
	void initializeGrid(); // calling the initialize method from Controller class
	void converge(); //-- calling all the Controller methods for all rooms in the grid
	Controller getElement(int x, int y);
};

#endif
