#ifndef RADAR_H_
#define RADAR_H_

#include "trackfile.h"
#include "comm.h"
#include <chrono>
#include <math.h>
class radar{
private:

	//list of hits
	//vector<aircraft> hit_list;

	//sublist of active hits (within airspace)
	//vector<aircraft> active_list;

	//temporary aircraft attributes
	string temp_id, temp_speed_x, temp_speed_y, temp_speed_z, temp_x, temp_y, temp_z, temp_time;

	//environment in feet
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

	//print extern all vector
	void printAll();

	static void populateEntered();

	static void* populateAirspace (void*);

	void printActive();

	static void* populateBuffer(void*);

	//void hit(aircraft ac);
	//void printHitList();
};

#endif /*RADAR_H_*/
