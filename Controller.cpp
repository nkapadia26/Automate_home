// --- Controller.cpp ---

#include <iostream>
//#include "userSettings.h"
#include "Controller.h"
#include "math.h"
#include <stdlib.h>
using namespace std;

Controller::Controller() {
      water_on = 0;
      heat_level = 0;
      window_level = 0;
      blind_level = 0;
      lighting_level = 0;
      door_close = 0;
}

void Controller::setLightLevel(double sunlight, double& curr_luminence, double user_setting, bool occupied) {
	// lets assume sunlight adds 50% of its luminence to the room when fully open blind (level 5)
	// And, with every level lower than that, luminence reduces by 10%
	// Also, for every higher light_level, luminence increases by 20.0 lumens  
	// As, we can not deliver continuous values of luminence, the resulting luminence would generally not be exactly equal to user_setting	
	double difference;
	difference = user_setting - curr_luminence;

	if (!occupied) {
		blind_level = 0;
		curr_luminence = low_luminence;
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
			new_lighting_level = lighting_level + (int) round(new_difference/20.0);
			curr_luminence = curr_luminence + 20.0*(new_lighting_level - lighting_level);
			lighting_level = new_lighting_level;
		}
	} // end else
}// end method

// -- Lets assume that each level of heating (+ve or -ve) can maintain a temperature-differential (inside/outside) of additional 10.0 degrees F
// -- We want to use the window to save heating/cooling energy 
// -- Each level of window opening erases 10% of temperature-differential
void Controller::calcHeatLevel(double outside_temp, double& curr_temp, double user_setting, bool occupied) {
	if (!occupied) {
		user_setting = low_temperature;
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
		heat_level = heat_level + (int) round(target_differential/10.0);
		curr_temp = curr_temp + round(target_differential/10.0)*10.0;
	}
	else { // -- both diffs are not of the same sign 
		// -- adjust heat_level first and window later
		heat_level = heat_level + (int) round(target_differential/10.0);
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
}// end method

void Controller::doorLocking (bool occupied) {
	if (!occupied) 
		door_close = 1;
}

void Controller::waterOn (bool triggered) {
	if (triggered)
		water_on = 1;
}
