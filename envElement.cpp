// --- envElement.cpp ---
/*
We consider a 2D grid of rooms in the single-storey house.
Each room having the same five sensors -- read from the sensor_readings.txt file by Parser class.
Five 2D dynamic arrays used to store the sensor readings -- each for the corresponding class of sensor.
*/
#include <stdlib.h>
#include "envElement.h"
using namespace std;

//The class constructor, although unusually long, allocates the object-variables 
envElement::envElement() {
	_leader_room.first = -1;
	_leader_room.second = -1; // by default, room is valid and self-contained (no leader)
	_valid_bit = 1;
}
tempSensor envElement::getTempElement() {
        return _temperature_reading;
}

lightSensor envElement::getLightElement() {
        return _luminence_reading;
}

doorSensor envElement::getDoorElement() {
        return _door_reading;
}

windowSensor envElement::getWindowElement() {
        return _window_reading;
}

fireSensor envElement::getFireElement() {
        return _fire_reading;
}

occupancySensor envElement::getOccElement() {
        return _occupancy_reading;
}

void envElement::setFireElement(bool triggered) {
	_fire_reading.setTrigger(triggered);
}

void envElement::setTempElement(double temperature) {
	_temperature_reading.setTemp(temperature);
}

void envElement::setLightElement(double luminence) {
	_luminence_reading.setLuminence(luminence);
}

void envElement::setDoorElement(bool locked) {
	_door_reading.setDoor(locked);
}

void envElement::setWindowElement(int open_level) {
	_window_reading.setOpenLevel(open_level);
}

void envElement::setBlindElement(int blind_level) {
        _window_reading.setBlindLevel(blind_level);
}

void envElement::setOccElement(bool occupied) {
	_occupancy_reading.setOccupancy(occupied);
}

void envElement::setLeader(int x, int y) {
	_leader_room.first = x;
	_leader_room.second = y;
}

bool envElement::leaderCheck() {
	return (_leader_room.first < 0)? 0 : 1;
}

bool envElement::getRoomValidity() {
	return _valid_bit;
}		

void envElement::setRoomValidity(bool valid_bit) {
	_valid_bit = valid_bit;
}
