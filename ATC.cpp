/*
 * ATC.cpp
 *
 *  Created on: 2019年11月15日
 *      Author: Dot dot
 */

#include "ATC.h"
#include "comm.h"
#include <chrono>
int GLOBAL_CLOCK=0;
vector<aircraft> airspace;
ATC::ATC() {
	// TODO Auto-generated constructor stub
	//this->aircraftlist=NULL;
}
ATC::ATC(vector<aircraft> aircraftlist){
	airspace=aircraftlist;
}
void* ATC::Collision_detection(void* arg){

	while(true){
	auto start = std::chrono::system_clock::now();
	string collision_message;
	//if global oval
	//
	for(unsigned int i =0;i<airspace.size();i++){
		for(unsigned int j =0;j<airspace.size();j++){
			if(i!=j){
				if(collision(airspace[i],airspace[j]))
					collision_message+="Collision happened with "+to_string(airspace[i].getID())+" and "+to_string(airspace[j].getID())+"\n";
			}
		}
	}
	cout << collision_message;
	auto end =  std::chrono::system_clock::now();
	cout << "Time to sleep "<<15000000-(chrono::duration_cast<chrono::milliseconds>(end - start).count())<<endl;
	usleep(15000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}

void ATC::Collision_handling(void* arg){

	//Find appropriate x,y,z for the plane.



	//Try different coordinates for aircraft.
	//After finding good coordinates, send them as an 'Aircraft' unit to comm and specify id, and all other details in it.
	//Comm will ask the plane to change its coordinates to this one's.

}

ATC::~ATC() {
	// TODO Auto-generated destructor stub
}

