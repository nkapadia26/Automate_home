// --- userSettings.cpp ---

#include <iostream>
#include "userSettings.h"
#include "Controller.h"
#include "math.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

userSettings::userSettings(Env env) {
        _x_dim = env.getGridSizes().first;
        _y_dims = env.getGridSizes().second;
	_temperature_grid = _temperature_vec_2d.get_allocator().allocate(_x_dim);
	_luminence_grid = _luminence_vec_2d.get_allocator().allocate(_x_dim);
	for (int i=0; i<_x_dim; i++) {
		_temperature_vec_2d.get_allocator().construct(&_temperature_grid[i], vector <double> (_y_dims[i]));
		_luminence_vec_2d.get_allocator().construct(&_luminence_grid[i], vector <double> (_y_dims[i]));	
	} 	
	
/*         _temperature_grid = new double*[_x_dim];
         _luminence_grid = new double*[_x_dim];
         for(int i = 0; i < _x_dim; i++) {
              _temperature_grid[i] = new double[_y_dim];
              _luminence_grid[i] = new double[_y_dim];
         }
*/
}


void userSettings::readUserSettings() {
	ifstream in_file;
	in_file.open("user_settings.txt");
	
	for (int i = 0; i<_x_dim; i++) {
		for (int j=0; j<_y_dims[i]; j++) {
			if (!in_file) {
				cout << "ERROR: Not enough user_setting values for the grid dimensions: " << endl;
				exit(1);	
			}
			in_file	>> _temperature_grid[i][j] >> _luminence_grid[i][j];
		}
	}
}

void userSettings::printSettings() {
	for (int i = 0; i<_x_dim; i++) {
                for (int j=0; j<_y_dims[i]; j++) {
			cout << _temperature_grid[i][j] << " " << _luminence_grid[i][j] << endl;
		}
	}
}
