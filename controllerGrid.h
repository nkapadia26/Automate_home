// --- controllerGrid.h ---

// Basically, holds the 2D array of Controller-class objects. Also, methods governing control-actions that consider neighborhood will go here.

#ifndef CONTROLLERGRID_H_
#define CONTROLLERGRID_H_

#include <iostream>
#include <vector>

class Env;
class Controller;

class controllerGrid {
private:
	vector <vector <Controller> > _control_vec_2d; // -- 2d vector
	vector <Controller> *_control_grid;  // -- pointer used to access the 2d vector
	Env* _env;
	userSettings* _us;
public:
	controllerGrid(int x_dim, const vector <int> &y_dims, Env* env, userSettings* us);
	void initializeGrid(); // calling the initialize method from Controller class
	void converge(); //-- calling all the Controller methods for all rooms in the grid
	Controller getElement(int x, int y);
};

#endif
