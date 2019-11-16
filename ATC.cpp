/*
 * ATC.cpp
 *
 *  Created on: 2019年11月15日
 *      Author: Dot dot
 */

#include "ATC.h"

ATC::ATC() {
	// TODO Auto-generated constructor stub
	//this->aircraftlist=NULL;
}
ATC::ATC(vector<aircraft> aircraftlist){
	this->aircraftlist=aircraftlist;
}
string ATC::Collision_detection(){
	string collision_message;
	for(int i =0;i<this->aircraftlist.size();i++){
		for(int j =0;j<this->aircraftlist.size();j++){
			if(i!=j){
				if(collision(aircraftlist[i],aircraftlist[j]))
					collision_message+="Collision happen with "+aircraftlist[i].getID()+" and "+aircraftlist[j].getID()+"\n";
			}
		}
	}
	return collision_message;
}

ATC::~ATC() {
	// TODO Auto-generated destructor stub
}

