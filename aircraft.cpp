#include "aircraft.h"
bool GLOBAL_OVAL=false;
aircraft::aircraft()
{
	this->old_x=0;
	this->old_y=0;
	this->OVAL=false;
	this->id=0;
	this->x=0;
	this->y=0;
	this->z=0;
	this->speed_x=0;
	this->speed_y=0;
	this->speed_z=0;
	this->time=0;
}

aircraft::aircraft(int id, int speed_x, int speed_y, int speed_z, int x, int y, int z, int time)
{
	this->OVAL=false;
	this->id = id;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
	this->time = time;
	this->old_x=0;
	this->old_y=0;
}

int aircraft::getID(){return this->id;}
int aircraft::getX(){return this->x;}
int aircraft::getY(){return this->y;}
int aircraft::getZ(){return this->z;}
int aircraft::getSpeedX(){return this->speed_x;}
int aircraft::getSpeedY(){return this->speed_y;}
int aircraft::getSpeedZ(){return this->speed_z;}
int aircraft::getTime(){return this->time;}

void aircraft::setID(int id){this->id = id;}
void aircraft::setX(int x){this->x = x;}
void aircraft::setY(int y){this->y = y;}
void aircraft::setZ(int z){this->z = z;}
void aircraft::setSpeedX(int speed_x){this->speed_x = speed_x;}
void aircraft::setSpeedY(int speed_y){this->speed_y = speed_y;}
void aircraft::setSpeedZ(int speed_z){this->speed_z = speed_z;}
void aircraft::setTime(int time){this->time = time;}


/*void aircraft::hit(map<string,int*>& mymap){
	int list[3] = {this->x,this->y,this->z};
	mymap.insert(pair<string,int*>(this->id,list));
}*/

void aircraft::fly() {
	this->x += this->speed_x;
	this->y += this->speed_y;
	this->z += this->speed_z;
}
aircraft::~aircraft(){

}


/*aircraft::~aircraft()
>>>>>>> f490360ad390ef7b919990c67e6c1a641c4df718
{
}*/
