#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
#include <pthread.h>

using namespace std;
class aircraft
{
private:
	//attributes
	string ID;
	int speed_x, speed_y, speed_z, x, y, z;
	//-1 id for unknown aircraft
	
public:
	aircraft();
	aircraft(string,float,float,float,float,float,float);
	virtual ~aircraft();
	
	//getters & setters
	float getX();
	float getY();
	float getZ();
	float getSpeedX();
	float getSpeedY();
	float getSpeedZ();
	void hit(map<string,float*>&);
	void fly();
};

#endif /*AIRCRAFT_H_*/
