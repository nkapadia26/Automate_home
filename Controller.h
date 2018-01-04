// --- Controller.h ---
// Controller-actions will determine how the next set of env_variables (sensor-readings) are affected.
// At each iteration, sensor readings are derived (computed or estimated) from the current env-variables and the controller inputs.
// Controller takes actions that attempt to maintain the environment close to the user-settings.

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <fstream>

class Env;

class userSettings;

class Controller {
private:
	bool _water_on; // --  1 or 0
	int _heat_level; // -- -9,..., -3, -2, -1, 0, 1, 2, 3, ..., 9
	int _lighting_level; // -- 0 to 5
	static const double _low_luminence = 10.0; // used when room unoccupied
	static const double _low_temperature = 60.0;
	static const double _high_temperature = 85.0;
//	Env* _env;
//	userSettings* _us;
public:
	Controller();
//	Controller(Env* env, userSettings* us);
//	Controller(int x, int y, Env* env, userSettings* us);
	inline void setWaterOn(bool water_on) { _water_on = water_on; }
	inline bool getWaterOn() { return _water_on; }
	inline void setHeatLevel(int level) { 
		_heat_level = level;
	}
	inline int getHeatLevel() { return _heat_level; }
//	inline void setWindowLevel(int window_level) { _window_level = window_level; } 	
	inline void setLightingLevel(int lighting_level) { _lighting_level = lighting_level; }
//	inline int getWindowLevel() { return _window_level; } 	
	inline int getLightingLevel() { return _lighting_level; }
//	inline void forceDoor(bool door_close) { _door_close = door_close; }
//	inline void setBlindLevel(int blind_level) { _blind_level = blind_level; }
//	inline bool getDoor() { return _door_close; }
//	inline int getBlindLevel() { return _blind_level; }
	// -- calculate new blind_level and calculate new lighting_level for target luminence (user_setting)
	//-- also, calculate resulting luminence
	void setLightLevel(int x, int y, Env* env, userSettings* us); 

	// -- Although temperature does not change instantaneously, here, we set the curr_temp in evironment for the next cyclic period
	// Temperature value in the environment will settle to a value close to the target supposedly by the end of the contol-cycle period
	// We calculate the window level and the heat_level for the target temperature-setting
	void calcHeatLevel(int x, int y, Env* env, userSettings* us);
	
        void doorLocking (int x, int y, Env* env, userSettings* us);
        void waterOn (int x, int y, Env* env, userSettings* us);
	void varInitialize(int x, int y, Env* env, userSettings* us);
};

#endif
