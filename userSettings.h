// --- userSettings.h ---
// Define the current set of user-preferences for a single room 
// A 2D array of such class-objects will be used to make controller decisions

#ifndef USERSETTINGS_H_
#define USERSETTINGS_H_

#include <iostream>
#include <fstream>
#include "Env.h"

class userSettings {
private:
	double** temperature_grid;
	double** luminence_grid;
public:
	inline userSettings::userSettings(Env env) {
		int x_dim, y_dim;
		x_dim = env.getGridSize().first; 
		y_dim = env.getGridSize().second;
		temperature_grid = new double*[x_dim];
		luminenece_grid = new double*[x_dim];
		for(int i = 0; i < x_dim; i++) {
	 	       temperature_grid[i] = new double[y_dim];
		       luminence_grid[i] = new double[y_dim];
		}
	}
	
	inline double getTemperature(int x_coord, int y_coord) const {
		this->temperature_grid[x_coord][y_coord];
	}
	inline double getLuminence(int x_coord, int y_coord) const {
                this->luminence_grid[x_coord][y_coord];
        }
	inline void setTemperature(int x_coord, int y_coord, double value) {
                this->temperature_grid[x_coord][y_coord] = value;
        }
        inline void setLuminence(int x_coord, int y_coord, double value) {
                this->luminence_grid[x_coord][y_coord] = value;
        }
	//friend class Controller;
};
