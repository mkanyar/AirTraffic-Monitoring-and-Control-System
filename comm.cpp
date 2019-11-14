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




}

comm::~comm()
{
}
