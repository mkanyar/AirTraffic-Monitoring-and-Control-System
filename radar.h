#ifndef RADAR_H_
#define RADAR_H_

#include "trackfile.h"
#include "comm.h"
#include <chrono>
#include <math.h>
class radar{
private:

	//temps to use in case manipulation is required
	string temp_id, temp_speed_x, temp_speed_y, temp_speed_z, temp_x, temp_y, temp_z, temp_time;

	//constant bounds of the airspace defined in the project description
	static const int upperX = 5280000; //in feet
	static const int lowerX = 0;
	static const int upperY = 5280000; //in feet
	static const int lowerY = 0;
	static const int upperZ = 25000; //in feet
	static const int lowerZ = 0;

public:
	radar();
	virtual ~radar();

	//functions used for displaying the vectors
	void printAll();
	void printActive();

	//functions used to populate the vectors
	static void populateEntered();
	static void* populateAirspace (void*);
	static void* populateBuffer(void*);
};

#endif /*RADAR_H_*/
