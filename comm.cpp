#include "comm.h"
#include <string>
    string comm:: getID(){return this->ID;};
    float comm::getX(){return this->x;}
   	float comm::getY(){return y;};
   	float comm::getZ(){return z;};

   	float comm::getSpeedX(){return speed_x;};
   	float comm::getSpeedY(){return speed_y;};
   	float comm::getSpeedZ(){return speed_z;};
   	float comm::getEntryTime(){return entry_time;};
   	void comm::changeSpeed(float x,float y,float z)
   	{
   	speed_x=x;
   	speed_y=y;
   	speed_z=z;
   	}

   	float comm::getSpeedX(){return x;};
   	float comm::getSpeedY(){return y;};
   	float comm::getSpeedZ(){return z;};
   	float comm::getEntryTime(){return entry_time;};
   	
comm::comm()
{

	    ID="";
		x=0;
		y=0;
		z=0;
	    speed_x=0;
		speed_y=0;
		speed_z=0;
		entry_time=0;
=======
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
