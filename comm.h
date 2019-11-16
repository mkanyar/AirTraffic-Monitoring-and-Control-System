#ifndef COMM_H_
#define COMM_H_
#include <iostream>
#include <string>
#include <vector>
#include "aircraft.h"

using namespace std;
class comm
{private:


    vector <aircraft> airplanes;

    /*NOTE: I think these attributes are for aircrafts only*/
    //string ID;
	//float speed_x, speed_y, speed_z, x, y, z, entry_time;



public:
	comm();
   ~comm();
  comm(vector<aircraft>);

    string getID();

    void receiveMessage(vector <string> tokens);


    /*NOTE: I think these methods are needed for aircrafts only*/
    //float getX();
   	//float getY();
   	//float getZ();
   	//float getSpeedX();
   	//float getSpeedY();
   	//float getSpeedZ();
   	//float getEntryTime();
   	//void changeSpeed(float,float,float);



	//reporting aircraft leaving airspace (sporadic)
};

#endif /*COMM_H_*/
