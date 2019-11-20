/*
 * ATC.h
 */

#ifndef SRC_ATC_H_
#define SRC_ATC_H_
#include "aircraft.h"
#include "trackfile.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;
extern int GLOBAL_CLOCK;
extern vector<aircraft> airspace;
class ATC {
private:
   // string& stringstream ;
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
		float vector_x = (float)(a.origin[0]-b.origin[0]);
		float vector_y = (float)(a.origin[1]-b.origin[1]);
		if(GLOBAL_OVAL || (a.OVAL&&b.OVAL)){
			if(abs(atempz-btempz)<=1000){
				cout << "case z"<<endl;
				bufferString+="We are at time ";
				bufferString+=to_string(a.getTime())+" and the aircrafts are going to collide at "+to_string(a.time+GLOBAL_CLOCK)+"\n";
				return true;
			}
           //multiply the feet by 5280 to convert in miles
			return sqrt(pow(vector_x,2)+pow(vector_y,2))<5*5280;
		}
		else if(a.OVAL){
			if(abs(atempz-btempz)<=1000){
				cout << "case z"<<endl;
				bufferString+="We are at time ";
				bufferString+=to_string(a.getTime()) + " and the aircrafts are going to collide at "+to_string(a.time+GLOBAL_CLOCK)+"\n";
			return true;
			}
			float vector_x = (float)(a.origin[0]-b.origin[0]);
			float vector_y = (float)(a.origin[1]-b.origin[1]);
			return sqrt(pow(vector_x,2)+pow(vector_y,2))<5*5280;
		}
		else if(b.OVAL)
			bufferString+="We are at time ";
		bufferString+=to_string(b.getTime()) + " and the aircrafts are going to collide at "+to_string(b.time+GLOBAL_CLOCK)+"\n";
			return false;
		//else if{}

			for(int i =0;i<5;i++){
				vector_x=a.getX()-b.getX();
				vector_y=a.getY()-b.getY();
				if(sqrt(pow(vector_x,2)+pow(vector_y,2))<3*5280 && abs(a.getZ()-b.getZ())<1000)
				{
				//add to  a message such that communication can do something

				return true;
				}
				atempx=a.getX()+a.getSpeedX();
				atempy=a.getY()+a.getSpeedY();
				atempz=a.getZ()+a.getSpeedZ();
				btempx=b.getX()+b.getSpeedX();
				btempy=b.getY()+b.getSpeedY();
				btempz=b.getZ()+b.getSpeedZ();
			}//
			bufferString+="We are at time ";
			bufferString+=to_string(b.getTime()) + " and the aircrafts are going to collide at "+to_string(b.time+GLOBAL_CLOCK)+"\n";
			return false;

	}

public:

	ATC();
	ATC(vector<aircraft> aircraftlist);
	static void* Collision_detection(void*);
	virtual ~ATC();



};

#endif /* SRC_ATC_H_ */
