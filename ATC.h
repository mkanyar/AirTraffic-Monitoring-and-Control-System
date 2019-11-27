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
	static const int upperX = 5280000;
	static const int lowerX = 0;
	static const int upperY = 5280000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;

	static void Collision_handling(aircraft* a1, aircraft* a2);

	//static bool global_oval(aircraft* a1){};

	static bool collision(aircraft* a, aircraft* b){

		int vector_x,vector_y;
		int atempx=a->getX()+a->getSpeedX();
		int atempy=a->getY()+a->getSpeedY();
		int atempz=a->getZ()+a->getSpeedZ();
		int btempx=b->getX()+b->getSpeedX();
		int btempy=b->getY()+b->getSpeedY();
		int btempz=b->getZ()+b->getSpeedZ();

		for(int i =0; i<10; i++){
			vector_x = atempx-btempx;
			vector_y = atempy-btempy;
			if(sqrt(pow(vector_x,2)+pow(vector_y,2))<(3*5280) && abs(atempz-btempz)<1000)
			{
				//add to  a message such that communication can do something
				while(pthread_mutex_lock( &buffstr )!=0);
				bufferString+= "COLLISION|Time: "+ to_string(GLOBAL_CLOCK)+"| Aircraft ID "+to_string(a->getID())+" and aircraft ID "+to_string(b->getID())+" will collide at "+to_string(GLOBAL_CLOCK+i)+"\n";
				pthread_mutex_unlock( &buffstr );
				//sleep(1);
				return true;
			}

			atempx=a->getX()+a->getSpeedX();
			atempy=a->getY()+a->getSpeedY();
			atempz=a->getZ()+a->getSpeedZ();
			btempx=b->getX()+b->getSpeedX();
			btempy=b->getY()+b->getSpeedY();
			btempz=b->getZ()+b->getSpeedZ();
			break;
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
