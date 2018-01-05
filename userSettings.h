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
	vector < vector <double> > _temperature_vec_2d;
	vector < vector <double> > _luminence_vec_2d;
	vector <double> *_temperature_grid;
	vector <double> *_luminence_grid;
	int _x_dim;
	vector <int> _y_dims;
public:
	userSettings(Env env);

/*	inline ~userSettings() {         
	      for(int i = 0; i < x_dim; i++) {
	              delete [] temperature_grid[x_dim];
        	      delete [] luminence_grid[x_dim];
       	      }
              delete [] temperature_grid;
              delete [] luminence_grid;
	}
*/	
	inline double getTemperature(int x_coord, int y_coord) const {
		return this->_temperature_grid[x_coord][y_coord];
	}
	inline double getLuminence(int x_coord, int y_coord) const {
                return this->_luminence_grid[x_coord][y_coord];
        }
	inline void setTemperature(int x_coord, int y_coord, double value) {
                this->_temperature_grid[x_coord][y_coord] = value;
        }
        inline void setLuminence(int x_coord, int y_coord, double value) {
                this->_luminence_grid[x_coord][y_coord] = value;
        }
	void readUserSettings();
	void printSettings();
	//friend class Controller;
};

#endif
