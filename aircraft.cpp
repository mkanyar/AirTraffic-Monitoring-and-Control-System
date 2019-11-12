#include "aircraft.h"

using namespace std;
string aircraft::getX(){return this->x;}
string aircraft::getY(){return this->y;}
string aircraft::getZ(){return this->z;}
string aircraft::getSpeedX(){return this->speed_x;}
string aircraft::getSpeedY(){return this->speed_y;}
string aircraft::getSpeedZ(){return this->speed_z;}
	
aircraft::aircraft()
{
}

aircraft::aircraft(string ID, string speed_x, string speed_y, string speed_z, string x, string y, string z)
{
	this->ID = ID;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
}

string* aircraft::hit(){
	string list[4] = {this->ID,this->x,this->y,this->z};
	return list;
}

aircraft::~aircraft()
{
}
