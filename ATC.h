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
extern float GLOBAL_CLOCK;
class ATC {
private:
	static vector<aircraft> airspace;
	static const int upperX = 100000;
	static const int lowerX = 0;
	static const int upperY = 100000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;
	static bool collision(aircraft a, aircraft b){
		float atempx=a.getX();
		float atempy=a.getY();
		float atempz=a.getZ();
		float btempx=b.getX();
		float btempy=b.getY();
		float btempz=b.getZ();
				//if b's z is smaller than a.z
				// and a.samller z is smaller than b.largest z
		for(int i =0;i<14;i++){
			if(abs(atempz-btempz)<=1000)
			{
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
			else if(abs(atempx-btempz)<=3)
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
