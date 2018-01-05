// --- controllerGrid.cpp ---

#include <stdlib.h>
#include "Env.h"
#include "userSettings.h"
#include "Controller.h"
#include "controllerGrid.h"
using namespace std;

controllerGrid::controllerGrid(int x_dim, const vector <int> &y_dims, Env* env, userSettings* us) {
	_env = env;
	_us = us;
       // cout << " x-y dims: " << _env->getGridSize().first << " " << _env->getGridSize().second << endl;
	_control_grid = _control_vec_2d.get_allocator().allocate(x_dim);
	for (int i = 0; i < x_dim; i++) {
		_control_vec_2d.get_allocator().construct(&_control_grid[i], vector <Controller> (y_dims[i]));
	}

/*	_control_grid = new Controller*[x_dim];
	for(int i = 0; i < x_dim; i++) 
	        _control_grid[i] = new Controller[y_dim];
*/
}

void controllerGrid::initializeGrid() {
	int x_dim;
	vector <int> y_dims;
	x_dim = _env->getGridSizes().first;
	y_dims = _env->getGridSizes().second;
	for (int i=0; i<x_dim; i++) {
		for (int j=0; j<y_dims[i]; j++) {
			_control_grid[i][j].varInitialize(i, j, _env, _us);	
		}
	} 
}

void controllerGrid::converge() {
	int x_dim;
	vector <int> y_dims;
	x_dim = _env->getGridSizes().first;
        y_dims = _env->getGridSizes().second;
	for (int i=0; i<x_dim; i++) {
               for (int j=0; j<y_dims[i]; j++) {
                       _control_grid[i][j].calcHeatLevel(i, j, _env, _us);
                       _control_grid[i][j].setLightLevel(i, j, _env, _us);
                       _control_grid[i][j].doorLocking(i, j, _env, _us);
                       _control_grid[i][j].waterOn(i, j, _env, _us);
               }
        } 
}

Controller controllerGrid::getElement(int x, int y) {
	return _control_grid[x][y];
}
			
