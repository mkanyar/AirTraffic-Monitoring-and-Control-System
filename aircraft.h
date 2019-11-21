#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
#include <pthread.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

extern bool GLOBAL_OVAL;
using namespace std;
class aircraft
{
private:

    int count=1;
	//-1 id for unknown aircraft

public:
    //attributes
    int id, speed_x, speed_y, speed_z, x, y, z, time;
	bool OVAL;
	int old_x,old_y;
	vector<int> origin;
	aircraft();
	aircraft(int,int,int,int,int,int,int,int);
	virtual ~aircraft();

	//getters & setters
	int getID();
	int getX();
	int getY();
	int getZ();
	int getSpeedX();
	int getSpeedY();
	int getSpeedZ();
	int getTime();

	void setID(int id);
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	void setSpeedX(int speed_x);
	void setSpeedY(int speed_y);
	void setSpeedZ(int speed_z);
	void setTime(int time);
	bool activated(int GLOBAL_CLOCK){
		if(!GLOBAL_CLOCK || !this->OVAL)
		{

			count = 1;
		}
		return GLOBAL_CLOCK>=this->time;
	}
	void setID(string id);
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setSpeedX(float speed_x);
	void setSpeedY(float speed_y);
	void setSpeedZ(float speed_z);
	void setTime(float time);
	bool activated(float clock);


	//for the oval function we assume the radius is 1 and the origin is at 90 degrees.
	void oval(){

		if(count == 1)
		{
			old_x=this->x;
			old_y=this->y;
			origin.push_back(this->x);
			origin.push_back(this->y-1);

		}
				if ((count%4)==0){
					this->x+=0;
					this->y+=0;
					count+=1;
				}

				if ((count%4)==1){
					this->x-=1;
					this->y+=-1;
					count+=1;
							}
				if ((count%4)==2){
					this->x+=1;
					this->y+=1;
					count+=1;

							}
				if ((count%4)==3){
					this->x+=-1;
					this->y+=1;
                    count+=1;

							}

	}
	//void hit(map<string,int*>&);
	void fly();

};
#endif /*AIRCRAFT_H_*/
