#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
#include <pthread.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class aircraft
{
private:
	//attributes
	int id, speed_x, speed_y, speed_z, x, y, z, time;
	//-1 id for unknown aircraft

public:
	aircraft();
	aircraft(int,int,int,int,int,int,int,int);
	virtual ~aircraft();

	//getters & setters
	int getID();
	int getX();
	int getY();
	int getZ();
	int getSpeedX();
	int getSpeedY();
	int getSpeedZ();
	int getTime();

	void setID(int id);
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	void setSpeedX(int speed_x);
	void setSpeedY(int speed_y);
	void setSpeedZ(int speed_z);
	void setTime(int time);

	//void hit(map<string,int*>&);
	void fly();
};

#endif /*AIRCRAFT_H_*/
