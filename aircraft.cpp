#include "aircraft.h"

aircraft::aircraft()
{
	this->id="";
	this->x=0;
	this->y=0;
	this->z=0;
	this->speed_x=0;
	this->speed_y=0;
	this->speed_z=0;
	this->time=0;
}

aircraft::aircraft(string id, float speed_x, float speed_y, float speed_z, float x, float y, float z, float time)
{
	this->id = id;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
	this->time = time;
}

string aircraft::getID(){return this->id;}
float aircraft::getX(){return this->x;}
float aircraft::getY(){return this->y;}
float aircraft::getZ(){return this->z;}
float aircraft::getSpeedX(){return this->speed_x;}
float aircraft::getSpeedY(){return this->speed_y;}
float aircraft::getSpeedZ(){return this->speed_z;}
float aircraft::getTime(){return this->time;}

void aircraft::setID(string id){this->id = id;}
void aircraft::setX(float x){this->x = x;}
void aircraft::setY(float y){this->y = y;}
void aircraft::setZ(float z){this->z = z;}
void aircraft::setSpeedX(float speed_x){this->speed_x = speed_x;}
void aircraft::setSpeedY(float speed_y){this->speed_y = speed_y;}
void aircraft::setSpeedZ(float speed_z){this->speed_z = speed_z;}
void aircraft::setTime(float time){this->time = time;}


/*void aircraft::hit(map<string,float*>& mymap){
	float list[3] = {this->x,this->y,this->z};
	mymap.insert(pair<string,float*>(this->id,list));
}*/

void aircraft::fly() {
	this->x += this->speed_x;
	this->y += this->speed_y;
	this->z += this->speed_z;
}
aircraft::~aircraft()
{
}
