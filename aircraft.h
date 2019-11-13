#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
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
	aircraft(string,int,int,int,int,int,int);
	virtual ~aircraft();
	
	//getters & setters
	int getX();
	int getY();
	int getZ();
	int getSpeedX();
	int getSpeedY();
	int getSpeedZ();
	void hit(map<string,int*>&);
};

#endif /*AIRCRAFT_H_*/
