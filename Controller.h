// --- Controller.h ---
// Controller-actions will determine how the next set of env_variables (sensor-readings) are affected.
// At each iteration, sensor readings are derived (computed or estimated) from the current env-variables and the controller inputs.
//  Controller takes actions that attempt to maintain the environment close to the user-settings.

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <fstream>

class Controller {
private:
	bool water_on; // --  1 or 0
	int heat_level; // -- -9,..., -3, -2, -1, 0, 1, 2, 3, ..., 9
	int window_level; // -- 0 to 5	
	int blind_level; // -- 0 to 5
	int lighting_level; // -- 0 to 5
	bool door_close; // force door shut
	static const double low_luminence = 10.0; // used when room unoccupied
	static const double low_temperature = 64.0;
public:
	Controller();
	inline void setWaterOn(bool water_on) { this->water_on = water_on; }
	inline void setHeatLevel(int level) { 
		heat_level = level;
	}
	inline void setWindowLevel(int window_level) { this->window_level = window_level; } 	
	inline void setLightingLevel(int lighting_level) { this->lighting_level = lighting_level; }
	inline void forceDoor(bool door_close) { this->door_close = door_close; }
	inline void setBlindLevel(int blind_level) { this->blind_level = blind_level; }
	
	// -- calculate new blind_level and calculate new lighting_level for target luminence (user_setting)
	//-- also, calculate resulting luminence
	void setLightLevel(double sunlight, double& curr_luminence, double user_setting, bool occupied); 

	// -- Although temperature does not change instantaneously, here, we set the curr_temp in evironment for the next cyclic period
	// Temperature value in the environment will settle to a value close to the target supposedly by the end of the contol-cycle period
	// We calculate the window level and the heat_level for the target temperature-setting
	void calcHeatLevel(double outside_temp, double& curr_temp, double user_setting, bool occupied);
	
        void doorLocking (bool occupied);
        void waterOn (bool triggered);
};

#endif
