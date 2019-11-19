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

using namespace std;
extern bool GLOBAL_OVAL;
class aircraft
{
private:
	//attributes
	int id, speed_x, speed_y, speed_z, x, y, z, time;
	int count = 0;
	//-1 id for unknown aircraft

public:
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

	//void hit(map<string,int*>&);
	void fly();
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
};

#endif /*AIRCRAFT_H_*/
