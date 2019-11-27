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
extern int GLOBAL_CLOCK;
extern string bufferString;
extern pthread_mutex_t buffstr;
extern pthread_mutex_t a_space;
extern pthread_mutex_t e_list;

class aircraft
{
private:
	//attributes
	int id, speed_x, speed_y, speed_z, x, y, z, time;
    int count=1;
	//-1 id for unknown aircraft

public:
	bool OVAL;
	bool entered;
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
	bool activate(string&);

	//for the oval function we assume the radius is 1 and the origin is at -90 degrees.
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
