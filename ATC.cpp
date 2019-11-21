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
void* ATC::Collision_detection(void* arg){

	while(true){
	auto start = std::chrono::system_clock::now();
	string collision_message;
	//if global oval
	//
	//cout << "airspace size is "<<airspace.size()<<endl;
	for(unsigned int i =0;i<airspace.size();i++){
		//cout << "entered here"<<endl;
		for(unsigned int j =0;j<airspace.size();j++){
			//cout << "entered second for loop"<<endl;
			if(i!=j){
				if(collision(airspace[i],airspace[j]))
					collision_message+="Collision happen with "+to_string(airspace[i]->getID())+" and "+to_string(airspace[j]->getID())+"\n";
					//cout << collision_message;
			}
		}
	}
	//cout << collision_message;
	auto end =  std::chrono::system_clock::now();
	//cout << "Execution time is  "<<(chrono::duration_cast<chrono::nanoseconds>(end - start).count())<<" nanoseconds"<<endl;
	usleep(5000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}

ATC::~ATC() {
	// TODO Auto-generated destructor stub
}

