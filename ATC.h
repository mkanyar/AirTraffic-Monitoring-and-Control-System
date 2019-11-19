/*
 * ATC.h
 */

#ifndef SRC_ATC_H_
#define SRC_ATC_H_
#include "aircraft.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
extern int GLOBAL_CLOCK;
extern vector<aircraft> airspace;
class ATC {
private:

	static const int upperX = 100000;
	static const int lowerX = 0;
	static const int upperY = 100000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;
	static bool collision(aircraft a, aircraft b){
		int atempx=a.getX();
		int atempy=a.getY();
		int atempz=a.getZ();
		int btempx=b.getX();
		int btempy=b.getY();
		int btempz=b.getZ();

		if(GLOBAL_OVAL || (a.OVAL&&b.OVAL)){
			if(abs(atempz-btempz)<=1000){
				cout << "case z"<<endl;
				return true;
			}
			float vector_x = (float)(a.origin[0]-b.origin[0]);
			float vector_y = (float)(a.origin[1]-b.origin[1]);
			return sqrt(pow(vector_x,2)+pow(vector_y,2))<5;
		}
		else if(a.OVAL){
			if(abs(atempz-btempz)<=1000){
				cout << "case z"<<endl;
			return true;
			}
			float vector_x = (float)(a.origin[0]-b.origin[0]);
			float vector_y = (float)(a.origin[1]-b.origin[1]);
			return sqrt(pow(vector_x,2)+pow(vector_y,2))<5;
		}
		for(int i =0;i<4;i++){
			if(abs(atempz-btempz)<=1000)
			{
				//if b's z is smaller than a.z
				// and a.samller z is smaller than b.largest z
				//cout<<"case z"<<endl;
				return true;
			}
			else if(abs(atempy-btempy)<=3)
			{
					//if a.lowest y is within b.highest y
					//or if a.highest y is within b.lowest y
				//cout<<"case y"<<endl;
				return true;
			}
			else if(abs(atempx-btempx)<=3)
			{
				//cout<<"case x"<<endl;
				return true;
			}
			atempx=a.getX()+a.getSpeedX();
			atempy=a.getY()+a.getSpeedY();
			atempz=a.getZ()+a.getSpeedZ();
			btempx=b.getX()+b.getSpeedX();
			btempy=b.getY()+b.getSpeedY();
			btempz=b.getZ()+b.getSpeedZ();
		}
			return false;
	}

public:

	ATC();
	ATC(vector<aircraft> aircraftlist);
	static void* Collision_detection(void*);
	virtual ~ATC();



};

#endif /* SRC_ATC_H_ */
