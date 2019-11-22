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
	//bool ifcollision = false;

	for(unsigned int i =0;i<airspace.size();i++){
		for(unsigned int j =0;j<airspace.size();j++){
			if(i!=j){
				if(collision(airspace[i],airspace[j])){
					collision_message+="Collision happened with "+to_string(airspace[i].getID())+" and "+to_string(airspace[j].getID())+"\n";
					Collision_handling(airspace[i],airspace[j]);
				}
			}
		}
	}
	cout << collision_message;
	auto end =  std::chrono::system_clock::now();
	cout << "Time to sleep "<<15000000-(chrono::duration_cast<chrono::milliseconds>(end - start).count())<<endl;
	usleep(15000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}

void ATC::Collision_handling(aircraft a1, aircraft a2){

	int i = 1.1;
	bool switchturn = false;

	int nowclock =GLOBAL_CLOCK;

	int savea1x = a1.getSpeedX();
	int savea2x = a2.getSpeedX();
	int savea1y = a1.getSpeedY();
	int savea2y = a2.getSpeedY();

	while (collision(a1,a2)){
		if(!switchturn){
			a1.setX(a2.getX()*i);
			switchturn = true;
		}
		else{
			a1.setX(-a2.getX()*i);

				switchturn = false;
		}


		i = i + 0.1;
	}
	while(nowclock! = GLOBAL_CLOCK);
	a1.setSpeedX(savea1x);
	a2.setSpeedX(savea2x);
	a1.setSpeedY(savea1y);
	a2.setSpeedY(savea2y);
	//NOT NEEDED
	//After finding good coordinates, send them as an 'Aircraft' unit to comm and specify id, and all other details in it.
	//Comm will ask the plane to change its coordinates to this one's.

}

ATC::~ATC() {
	// TODO Auto-generated destructor stub
}

