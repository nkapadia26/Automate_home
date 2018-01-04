// --- Controller.cpp ---

#include <iostream>
#include "Env.h"
#include "userSettings.h"
#include "Controller.h"
#include "math.h"
#include <stdlib.h>
using namespace std;

Controller::Controller() {}
/*
Controller::Controller(Env* env, userSettings* us) {
      _water_on = 0;
      _heat_level = 0;
      _lighting_level = 0;
      env = env;
      us = us;
}*/
/*
Controller::Controller(int x, int y, Env* env, userSettings* us) {
      _water_on = 0;
      _heat_level = 0;
      _lighting_level = 0;
      x_coord = x;
      y_coord = y;
      env = env;
      us = us;
}
*/
void Controller::varInitialize(int x_coord, int y_coord, Env* env, userSettings* us) {
	//cout << " initial heat_level and lighting_level should reflect initial env " << endl;
	
	double curr_luminence;
	int blind_level, sunlight;
	curr_luminence = env->getLightData(x_coord, y_coord).getLuminence();
	blind_level = env->getWindowData(x_coord, y_coord).getBlindLevel();
	sunlight = env->getSunlight();
	curr_luminence = curr_luminence - sunlight*blind_level*0.1; // this comes from lighting_level
	_lighting_level = max(round(curr_luminence/20.0), 0.0); // -- one level corresponds to 20 lumens
	
	int window_level;
        double outside_temp, curr_temp, eff_diff;
        window_level = env->getWindowData(x_coord, y_coord).getOpenLevel();
        outside_temp = env->getOutsideTemp();
        curr_temp = env->getTempData(x_coord, y_coord).getTemp();
	// -- Each level of window opening erases 10% of temperature-differential
	eff_diff = (curr_temp - outside_temp) + window_level*0.1*(curr_temp - outside_temp);
	// -- each level of heating (+ve or -ve) can maintain a temperature-differential (inside/outside) of additional 10.0 degrees F
	// eff_diff that the heat_level has to mitigate
	_heat_level = round(eff_diff/10.0);
	if ((_heat_level > 9) || (_heat_level < -9)) 
		cout << "Warning: Controller::_heat_level initialized to an extreme level " << _heat_level << endl;	

	// -- water_on will initialize to 0
	_water_on = 0;
	//cout << "controller settings: " << _lighting_level << " " << _heat_level << " " << _water_on << endl;
}

void Controller::setLightLevel(int x_coord, int y_coord, Env* env, userSettings* us) {
	// lets assume sunlight adds 50% of its luminence to the room when fully open blind (level 5)
	// And, with every level lower than that, luminence reduces by 10%
	// Also, for every higher light_level, luminence increases by 20.0 lumens  
	// As, we can not deliver continuous values of luminence, the resulting luminence would generally not be exactly equal to user_setting	
	double difference, user_setting, curr_luminence, sunlight;
	bool occupied;
	int blind_level;
	user_setting = us->getLuminence(x_coord, y_coord);
	curr_luminence = env->getLightData(x_coord, y_coord).getLuminence();
	occupied = env->getOccData(x_coord, y_coord).getOccupancy();
	blind_level = env->getWindowData(x_coord, y_coord).getBlindLevel();
	sunlight = env->getSunlight();

	difference = user_setting - curr_luminence;

	if (!occupied) {
		blind_level = 0;
		curr_luminence = _low_luminence;
	}
	else { // someone in the room
		int reqd_blind_move = 0;	
		double new_difference = 0;
		reqd_blind_move = (int) round(difference/(0.1*sunlight));
		if ((blind_level + reqd_blind_move) > 5) {
			new_difference = difference - 0.1*sunlight*(5 - blind_level); // reducing the difference
			blind_level  = 5;
		} else if ((blind_level + reqd_blind_move) < 0) {
			new_difference = difference + 0.1*sunlight*(blind_level); // reducing -ve difference
			blind_level = 0;
		} else { // -- target luminence can be attained just by blind-adjustment
			blind_level = blind_level + reqd_blind_move;
		}
		curr_luminence = curr_luminence + (difference - new_difference); //luminence updated after blind movement
		if (new_difference != 0) { // -- we need to adjust the lighting_level also
			int new_lighting_level;
			new_lighting_level = _lighting_level + (int) round(new_difference/20.0);
			curr_luminence = curr_luminence + 20.0*(new_lighting_level - _lighting_level);
			_lighting_level = new_lighting_level;
		}
	} // end else
	// update the env variables that result from the controller actions
	env->setBlindData(x_coord, y_coord, blind_level);
	env->setLightData(x_coord, y_coord, curr_luminence);
	if ((x_coord == 1) && (y_coord == 2)) {
                cout << " lighting level " << _lighting_level << endl;
		cout << "blind_level: " << env->getWindowData(x_coord, y_coord).getBlindLevel();
       		cout << "  luminence: " <<  env->getLightData(x_coord, y_coord).getLuminence() << endl;
		cout << " blind_level and curr_luminence: " << blind_level << " " << curr_luminence << endl << endl; 
	}
}// end method

// -- Lets assume that each level of heating (+ve or -ve) can maintain a temperature-differential (inside/outside) of additional 10.0 degrees F
// -- We want to use the window to save heating/cooling energy 
// -- Each level of window opening erases 10% of temperature-differential
void Controller::calcHeatLevel(int x_coord, int y_coord, Env* env, userSettings* us) {
	int window_level;
	double outside_temp, curr_temp, user_setting;
	bool occupied;
	window_level = env->getWindowData(x_coord, y_coord).getOpenLevel();
	outside_temp = env->getOutsideTemp();
	curr_temp = env->getTempData(x_coord, y_coord).getTemp();
	user_setting = us->getTemperature(x_coord, y_coord);
	occupied = env->getOccData(x_coord, y_coord).getOccupancy();

	if (!occupied) {
		if (outside_temp < _low_temperature)
			user_setting = _low_temperature;
		else if (outside_temp > _high_temperature)
			user_setting = _high_temperature;
		else user_setting = outside_temp;
	}			
	double io_differential, target_differential;  int window_move;
	io_differential = outside_temp - curr_temp;
	target_differential = user_setting - curr_temp;
	if(((io_differential > 0) && (target_differential > 0)) || ((io_differential < 0) && (target_differential < 0))) {
	// target_temp and outside temp in the same direction -- adjust window first and heat_level later
		window_move = 5 - window_level; window_level = 5;
		curr_temp = curr_temp +  window_move*0.1*io_differential;
		// update differentials
		io_differential = outside_temp - curr_temp;
	        target_differential = user_setting - curr_temp;
		_heat_level = _heat_level + (int) round(target_differential/10.0);
		curr_temp = curr_temp + round(target_differential/10.0)*10.0;
	}
	else { // -- both diffs are not of the same sign 
		// -- adjust heat_level first and window later
		_heat_level = _heat_level + (int) round(target_differential/10.0);
		curr_temp = curr_temp + round(target_differential/10.0)*10.0;
		// update differentials
		io_differential = outside_temp - curr_temp;
                target_differential = user_setting - curr_temp;
		window_move = target_differential/((0.1)*io_differential);
		if((window_level + window_move) > 5) window_move = 5 - window_level;
		else if ((window_level + window_move) < 0) window_move = -window_level;
		window_level = window_level + window_move;
		curr_temp = curr_temp + window_move*0.1*io_differential;
	}
	// update the env member variables -- closing Env-Controller loop
	env->setWindowData(x_coord, y_coord, window_level);
	env->setTempData(x_coord, y_coord, curr_temp);
	
	if ((x_coord == 1) && (y_coord == 2)) {
		cout << " -- heat level: " << _heat_level << endl;
		cout << " env-temp " << env->getTempData(x_coord, y_coord).getTemp();
		cout << "  env- open level " <<  env->getWindowData(x_coord, y_coord).getOpenLevel() << endl;
		cout << " window_level and curr_temp: " << window_level << " " << curr_temp << endl << endl;
	}
}// end method

void Controller::doorLocking(int x_coord, int y_coord, Env* env, userSettings* us) {
	bool occupied, door_locked;
	occupied = env->getOccData(x_coord, y_coord).getOccupancy();
	door_locked = env->getDoorData(x_coord, y_coord).getDoor();	
	if (!occupied && !door_locked) {
		env->setDoorData(x_coord, y_coord, 1);
	}
	if ((x_coord == 1) && (y_coord == 2)) {
		cout << "env-door-locked " << env->getDoorData(x_coord, y_coord).getDoor() << endl << endl;
	}	
}

void Controller::waterOn(int x_coord, int y_coord, Env* env, userSettings* us) {
	bool triggered;
	triggered = env->getFireData(x_coord, y_coord).getTrigger();
	if (triggered) {
		_water_on = 1;
		env->setFireData(x_coord, y_coord, 0); // once water is ON, turn off fire-alarm
	}
	if ((x_coord == 1) && (y_coord == 2)) {
		cout << " env-fire " << env->getFireData(x_coord, y_coord).getTrigger();
		cout << " water ON " << _water_on << endl << endl;
        }		
}
