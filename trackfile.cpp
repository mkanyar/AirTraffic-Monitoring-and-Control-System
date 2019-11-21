/*
 * trackfile.cpp
 *
 *  Created on: 13-Nov-2019
 *      Author: Aaron Liang
 */

#include "trackfile.h"
#include "aircraft.h"

//extern string from radar.h
string bufferString = "";

vector<aircraft*> GLOBAL_AIRCRAFT_LIST;
vector<aircraft*> airspace;
vector<aircraft*> entered_list;


trackfile::trackfile() {
	this->ac_position.setID(0);
	this->ac_position.setX(0);
	this->ac_position.setY(0);
	this->ac_position.setZ(0);
	this->ac_position.setSpeedX(0);
	this->ac_position.setSpeedY(0);
	this->ac_position.setSpeedZ(0);
	this->ac_position.setTime(0);
}

trackfile::trackfile(aircraft ac) {
	this->ac_position = ac;
}

void trackfile::newCurrentPosition(int id, int speed_x, int speed_y, int speed_z, int x, int y, int z, int time) {

	//current becomes previous
	aircraft previous_position = this->ac_position;

	//save previous to history
	this->ac_position_history.push_back(previous_position);

	//update new current position
	this->ac_position.setID(id);
	this->ac_position.setX(x);
	this->ac_position.setY(y);
	this->ac_position.setZ(z);
	this->ac_position.setSpeedX(speed_x);
	this->ac_position.setSpeedY(speed_y);
	this->ac_position.setSpeedZ(speed_z);
	this->ac_position.setTime(time);
}

void* trackfile::write_file_thread(void* mys){
	int i = 5;
	const char* s;
	while(i>0){
	//while(pthread_mutex_lock( &mutex1 )!=0);
	//cout << global_clock<<" Got lock"<<endl;
	s = bufferString.c_str();
	//cout << global_clock << " Start writing"<<endl;
	FILE *pFile2;

	pFile2 = fopen("Tracker.txt", "a");
	if(pFile2==NULL) {
	    perror("Error opening file.");
	}
	else {
		fprintf(pFile2, "%s", s);
	}
	fclose(pFile2);
	//cout << s <<endl;
	i--;
	//global_clock++;
	//cout << global_clock<<" Finish writing."<<endl;
	//pthread_mutex_unlock( &mutex1 );
	sleep(60);
	}
}


//getters
aircraft trackfile::getCurrentPosition() {
	return this->ac_position;
}

vector<aircraft> trackfile::getPreviousPositions() {
	return this->ac_position_history;
}




trackfile::~trackfile() {
	// TODO Auto-generated destructor stub
}
