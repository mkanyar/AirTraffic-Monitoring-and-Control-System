#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
#include <pthread.h>
#include <fstream>
#include <vector>

using namespace std;
class aircraft
{
private:
	//attributes
	string id;
	float speed_x, speed_y, speed_z, x, y, z, time;
	//-1 id for unknown aircraft

public:
	aircraft();
	aircraft(string,float,float,float,float,float,float,float);
	virtual ~aircraft();

	//getters & setters
	string getID();
	float getX();
	float getY();
	float getZ();
	float getSpeedX();
	float getSpeedY();
	float getSpeedZ();
	float getTime();

	void setID(string id);
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setSpeedX(float speed_x);
	void setSpeedY(float speed_y);
	void setSpeedZ(float speed_z);
	void setTime(float time);

	//void hit(map<string,float*>&);
	void fly();
};

#endif /*AIRCRAFT_H_*/
