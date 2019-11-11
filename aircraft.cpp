#include "aircraft.h"

int aircraft::getX(){return this->x;}
int aircraft::getY(){return this->y;}
int aircraft::getZ(){return this->z;}
int aircraft::getSpeedX(){return this->speed_x;}
int aircraft::getSpeedY(){return this->speed_y;}
int aircraft::getSpeedZ(){return this->speed_z;}
	
aircraft::aircraft()
{
}

aircraft::aircraft(std::string ID, int speed_x, int speed_y, int speed_z, int x, int y, int z)
{
	this->ID = ID;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
}

std::map<std::string,int[]>aircraft::hit(){
	std::map<std::string,int[]> a;
	int list[3] = {this->x,this->y,this->z};
	a[this->ID] = list;
	return a;
}

aircraft::~aircraft()
{
}
