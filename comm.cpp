#include "comm.h"
#include "aircraft.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

/*NOTE: I think these attributes are for aircrafts only*/
    //string comm:: getID(){return this->ID;};
    //float comm::getX(){return this->x;}
   	//float comm::getY(){return y;};
   	//float comm::getZ(){return z;};

//   	float comm::getSpeedX(){return speed_x;};
//   	float comm::getSpeedY(){return speed_y;};
//   	float comm::getSpeedZ(){return speed_z;};
//   	float comm::getEntryTime(){return entry_time;};
//   	void comm::changeSpeed(float x,float y,float z)
//   	{
//   	speed_x=x;
//   	speed_y=y;
//   	speed_z=z;
//   	}

   	void comm::receiveMessage(vector <string> tokens){
   		string TaskNumber = tokens[0];
   		stringstream transform(TaskNumber);
   		int TaskNumberInt = 0;
   		transform >> TaskNumberInt;

   		switch(TaskNumberInt){
   				case 1:

   					break;
   				case 2:

   					break;
   				case 3:

   					break;
   				case 4:

   					break;
   				case 5:

   					break;
   				case 6:

   					break;
   				case 7:
   					break;
   				case 8:

   					break;
   				case 9:
   					break;
   				//default:
   				//	cout<<"Invalid command, please try again.";
   				}
   	}



comm::comm(vector <aircraft> CollectedPlanes)
{
	airplanes = CollectedPlanes;

	/*NOTE: I think these attributes are for aircrafts only*/
//	    ID="";
//		x=0;
//		y=0;
//		z=0;
//	    speed_x=0;
//		speed_y=0;
//		speed_z=0;
//		entry_time=0;

}

comm::~comm()
{
}
