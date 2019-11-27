/*
 * ATC.cpp
 *
 *  Created on: 2019年11月15日
 *      Author: Dot dot
 */

#include "ATC.h"
#include "trackfile.h"
#include <chrono>

ATC::ATC() {
	// TODO Auto-generated constructor stub
	//this->aircraftlist=NULL;
}
ATC::ATC(vector<aircraft*> aircraftlist){
	airspace=aircraftlist;
}
void ATC::Collision_handling(aircraft* a1, aircraft* a2){

	float i = 0.03;
		float j = 3;
		bool switchturn = false;

		int nowclock = GLOBAL_CLOCK;

		int savea1x = a1->getSpeedX();
		int savea2x = a2->getSpeedX();
		int savea1y = a1->getSpeedY();
		int savea2y = a2->getSpeedY();

		while (collision(a1, a2)){
			a1->setSpeedX(a2->getSpeedX()*i);
			a1->setSpeedY(a2->getSpeedY()*i);
			a2->setSpeedX(a2->getSpeedX()*j);
			a2->setSpeedY(a2->getSpeedY()*j);
			if(i>0)
				i = i * 0.1;
			break;
		}
		while(nowclock == GLOBAL_CLOCK);
		a1->setSpeedX(savea1x);
		a2->setSpeedX(savea2x);
		a1->setSpeedY(savea1y);
		a2->setSpeedY(savea2y);
}

void* ATC::Collision_detection(void* arg){

	while(true){
	auto start = std::chrono::system_clock::now();
	string collision_message;
	//if global oval
	//
	//cout << "airspace size is "<<airspace.size()<<endl;
	pthread_mutex_lock( &a_space );
	for(unsigned int i =0;i<airspace.size();i++){
		//cout << "entered here"<<endl;
		for(unsigned int j =0;j<airspace.size();j++){
			//cout << "entered second for loop"<<endl;
			if(i!=j){
				if(airspace[i]->getID() != -1 || airspace[j]->getID() != -1){
					if(collision(airspace[i],airspace[j]))
					{
						//collision_message+="Collision happen with "+to_string(airspace[i]->getID())+" and "+to_string(airspace[j]->getID())+"\n";
						Collision_handling(airspace[i],airspace[j]);
						/*airspace[i]->setZ(airspace[i]->getZ()+500);
						airspace[j]->setZ(airspace[j]->getZ()-500);*/

					}
				}
			}
		}
	}
	pthread_mutex_unlock( &a_space );
	//cout << collision_message;
	auto end =  std::chrono::system_clock::now();
	//cout << "Execution time is  "<<(chrono::duration_cast<chrono::nanoseconds>(end - start).count())<<" nanoseconds"<<endl;
	usleep(5000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}



ATC::~ATC() {
	// TODO Auto-generated destructor stub
}

