#ifndef COMM_H_
#define COMM_H_
#include <iostream>
#include <string>

using namespace std;
class comm
{private:
    string ID;
	float speed_x, speed_y, speed_z, x, y, z, entry_time,changeSpeedX,changeSpeedY;

public:
	comm();
   ~comm();
  comm(string,float,float,float,float,float,float,float);

    string getID();
    float getX();
   	float getY();
   	float getZ();
   	float getSpeedX();
   	float getSpeedY();
   	float getSpeedZ();
   	float getEntryTime();
   	void setchangeSpeedX(float);
   	void setchangeSpeedY(float);



	//reporting aircraft leaving airspace (sporadic)
};

#endif /*COMM_H_*/
