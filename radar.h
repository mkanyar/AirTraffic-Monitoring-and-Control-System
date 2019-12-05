#ifndef RADAR_H_
#define RADAR_H_

#include "trackfile.h"
#include "comm.h"
#include <chrono>
#include <math.h>
class radar{
private:

	string temp_id, temp_speed_x, temp_speed_y, temp_speed_z, temp_x, temp_y, temp_z, temp_time;
	static const int upperX = 5280000;
	static const int lowerX = 0;
	static const int upperY = 5280000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;

public:
	radar();
	virtual ~radar();

	void readInput();
	void printAll();

	static void populateEntered();

	static void* populateAirspace (void*);

	void printActive();

	static void* populateBuffer(void*);
};

#endif /*RADAR_H_*/
