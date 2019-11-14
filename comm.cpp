#include "comm.h"
#include <string>
    string comm:: getID(){return this->ID;};
    float comm::getX(){return this->x;}
   	float comm::getY(){return y;};
   	float comm::getZ(){return z;};
   	float comm::getSpeedX(){return x;};
   	float comm::getSpeedY(){return y;};
   	float comm::getSpeedZ(){return z;};
   	float comm::getEntryTime(){return entry_time;};
   	void comm::setchangeSpeedX(float x)
   	{
   	speed_x=x;
   	}
   	void comm::setchangeSpeedY(float y)
   	{

   	 speed_y=y;

   	}
comm::comm()
{
	this->ID="";
		this->x=0;
		this->y=0;
		this->z=0;
		this->speed_x=0;
		this->speed_y=0;
		this->speed_z=0;

}

comm::~comm()
{
}
