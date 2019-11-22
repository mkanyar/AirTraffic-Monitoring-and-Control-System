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
class ATC {
private:
	// string& stringstream ;
	static const int upperX = 100000;
	static const int lowerX = 0;
	static const int upperY = 100000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;
	static bool collision(aircraft* a, aircraft* b){
		int vector_x,vector_y;
		int atempx=a->getX();
		int atempy=a->getY();
		int atempz=a->getZ();
		int btempx=b->getX();
		int btempy=b->getY();
		int btempz=b->getZ();
		for(int i =0;i<10;i++){
			vector_x=atempx-btempx;
			vector_y=atempy-btempy;
			if(sqrt(pow(vector_x,2)+pow(vector_y,2))<(3*5280) && abs(atempz-btempz)<1000)
			{
				//add to  a message such that communication can do something
				while(pthread_mutex_lock( &buffstr )!=0);
				bufferString+=to_string(GLOBAL_CLOCK)+", aircraft id "+to_string(a->getID())+" and aircraft id "+to_string(b->getID())+" have collision at "+to_string(GLOBAL_CLOCK+i)+".\n";
				pthread_mutex_unlock( &buffstr );
				return true;
			}
			atempx=a->getX()+a->getSpeedX();
			atempy=a->getY()+a->getSpeedY();
			atempz=a->getZ()+a->getSpeedZ();
			btempx=b->getX()+b->getSpeedX();
			btempy=b->getY()+b->getSpeedY();
			btempz=b->getZ()+b->getSpeedZ();
		}//

		return false;

	}

public:

	ATC();
	ATC(vector<aircraft*> aircraftlist);
	static void* Collision_detection(void*);
	virtual ~ATC();



};

#endif /* SRC_ATC_H_ */
