// --- userSettings.cpp ---

#include <iostream>
#include "userSettings.h"
#include "Controller.h"
#include "math.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

void userSettings::readUserSettings() {
	ifstream in_file;
	in_file.open("user_settings.txt");
	
	for (int i = 0; i<_x_dim; i++) {
		for (int j=0; j<_y_dim; j++) {
			if (!in_file) {
				cout << "ERROR: Not enough user_setting values for the grid dimensions: " << _x_dim << " " << _y_dim << endl;
				exit(1);	
			}
			in_file	>> _temperature_grid[i][j] >> _luminence_grid[i][j];
		}
	}
}

void userSettings::printSettings() {
	for (int i = 0; i<_x_dim; i++) {
                for (int j=0; j<_y_dim; j++) {
			cout << _temperature_grid[i][j] << " " << _luminence_grid[i][j] << endl;
		}
	}
}
