#include "aircraft.h"

using namespace std;
int aircraft::getX(){return this->x;}
int aircraft::getY(){return this->y;}
int aircraft::getZ(){return this->z;}
int aircraft::getSpeedX(){return this->speed_x;}
int aircraft::getSpeedY(){return this->speed_y;}
int aircraft::getSpeedZ(){return this->speed_z;}
	
aircraft::aircraft()
{
	this->ID="";
	this->x=0;
	this->y=0;
	this->z=0;
	this->speed_x=0;
	this->speed_y=0;
	this->speed_z=0;
}

aircraft::aircraft(string ID, int speed_x, int speed_y, int speed_z, int x, int y, int z)
{
	this->ID = ID;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
}

void aircraft::hit(map<string,int*>& mymap){
	int list[3] = {this->x,this->y,this->z};
	mymap.insert(pair<string,int*>(this->ID,list));
}
void aircraft::fly(){
	this->x+=this->speed_x;
	this->y+=this->speed_y;
	this->z+=this->speed_z;
}
aircraft::~aircraft()
{
}
