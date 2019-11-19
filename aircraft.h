#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include <iostream>
#include <map>
#include <string>
#include <pthread.h>
#include <fstream>
#include <vector>

extern bool GLOBAL_OVAL;
using namespace std;
class aircraft
{
private:
	//attributes
	string id;
	int speed_x, speed_y, speed_z, x, y, z, time,old_x,old_y;



	bool OVAL_BOOL;
    int count=1;
	//-1 id for unknown aircraft

public:
	//float safe_space[2][3];
	aircraft();
	vector<int> origin;
	float x_origin,y_origin;
	aircraft(string,float,float,float,float,float,float,float);
	virtual ~aircraft();

	//getters & setters
	string getID();
	float getX();
	float getY();
	float getZ();
	float getSpeedX();
	float getSpeedY();
	float getSpeedZ();
	float getTime();
	void get_status(){
		cout <<this->getID()<<","<<this->getSpeedX()<<","<<this->getSpeedY()<<","<<this->getSpeedZ()<<","<<
				this->getX()<<","<<this->getY()<<","<<this->getZ()<<endl;
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
			x_origin=this->x;
			y_origin=this->y-1;
			origin.push_back(x_origin);
			origin.push_back(y_origin);

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



	//void hit(map<string,float*>&);
	void fly();


#endif /*AIRCRAFT_H_*/
