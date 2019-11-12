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
	string speed_x, speed_y, speed_z, x, y, z;
	//-1 id for unknown aircraft
	
public:
	aircraft();
	aircraft(string ID, string speed_x, string speed_y, string speed_z, string x, string y, string z);
	virtual ~aircraft();
	
	//getters & setters
	string getX();
	string getY();
	string getZ();
	string getSpeedX();
	string getSpeedY();
	string getSpeedZ();
	string* hit();
};

#endif /*AIRCRAFT_H_*/
