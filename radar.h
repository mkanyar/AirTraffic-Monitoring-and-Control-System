#ifndef RADAR_H_
#define RADAR_H_

#include "trackfile.h"
#include "aircraft.h"


class radar : public trackfile{
private:

	//list of hits
	vector<aircraft> hit_list;

	//sublist of active hits (within airspace)
	vector<aircraft> active_list;

	//temporary aircraft attributes
	string temp_id, temp_speed_x, temp_speed_y, temp_speed_z, temp_x, temp_y, temp_z, temp_time;

	//environment
	static const int upperX = 100000;
	static const int lowerX = 0;
	static const int upperY = 100000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;

public:
	radar();
	virtual ~radar();

	void hit(aircraft ac);

	void readInputFile();

	void printHitList();

	void checkActive (int time);

	void printActive();

	void populateBuffer();

};

#endif /*RADAR_H_*/
