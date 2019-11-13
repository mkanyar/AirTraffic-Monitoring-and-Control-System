#include "aircraft.h"

using namespace std;
float aircraft::getX(){return this->x;}
float aircraft::getY(){return this->y;}
float aircraft::getZ(){return this->z;}
float aircraft::getSpeedX(){return this->speed_x;}
float aircraft::getSpeedY(){return this->speed_y;}
float aircraft::getSpeedZ(){return this->speed_z;}
	
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

aircraft::aircraft(string ID, float speed_x, float speed_y, float speed_z, float x, float y, float z)
{
	this->ID = ID;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
}

void aircraft::hit(map<string,float*>& mymap){
	float list[3] = {this->x,this->y,this->z};
	mymap.insert(pair<string,float*>(this->ID,list));
}
void aircraft::fly(){
	this->x+=this->speed_x;
	this->y+=this->speed_y;
	this->z+=this->speed_z;
}
aircraft::~aircraft()
{
}
