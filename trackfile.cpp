/*
 * trackfile.cpp
 *
 *  Created on: 13-Nov-2019
 *      Author: Aaron Liang
 */

#include "trackfile.h"
vector<aircraft*> entered_list;
vector<aircraft*> airspace;
vector<aircraft*> GLOBAL_AIRCRAFT_LIST;
unsigned int line = 0;
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

	//persist onto a text file
	log_file.open ("log.txt");

	if (!log_file) {

		cout << "Unable to open log.txt file" << endl;

		exit(1);
	}


	log_file.close();

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
	int i = 0;
	const char* s;
	while(true){

	while(pthread_mutex_lock( &buffstr )!=0);
	s = bufferString.c_str();
	pthread_mutex_unlock( &buffstr );
	FILE *pFile2;
	if(i==0){
		pFile2 = fopen("Tracker.txt", "w");
		i++;
	}
	else{
		pFile2 = fopen("Tracker.txt", "a");
	}

	if(pFile2==NULL) {
	    perror("Error opening file.");
	}
	else {
		fprintf(pFile2, "%s", s);
	}
	fclose(pFile2);
	bufferString="";
	line=0;
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
