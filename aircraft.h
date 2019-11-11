#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
class aircraft
{
private:
	//attributes
	std::string ID;
	int speed_x, speed_y, speed_z, x, y, z;
	//-1 id for unknown aircraft
	
public:
	aircraft();
	aircraft(std::string ID, int speed_x, int speed_y, int speed_z, int x, int y, int z);
	virtual ~aircraft();
	
	//getters & setters
	int getX();
	int getY();
	int getZ();
	int getSpeedX();
	int getSpeedY();
	int getSpeedZ();
	std::map<std::string,int[]> hit();
};

#endif /*AIRCRAFT_H_*/
