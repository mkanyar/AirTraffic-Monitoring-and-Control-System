/*
 * trackfile.cpp
 *
 *  Created on: 13-Nov-2019
 *      Author: Aaron Liang
 */

#include "trackfile.h"

trackfile::trackfile() {
	this->ac_position.setID("");
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

void trackfile::newCurrentPosition(string id, float speed_x, float speed_y, float speed_z, float x, float y, float z, float time) {

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

/*	friend ostream & operator << (ostream &out, const Aircraft & obj)
	{
		out << obj.id << ","
			<<obj.speed_x<< ","
			<<obj.speed_y<< ","
			<<obj.speed_z<< ","
			<<obj.x<< ","
			<<obj.y<< ","
			<<obj.z<< ","
			<<obj.time<<endl;

		return out;
	}*/



	//log_file << previous_position << "\n";
	//TODO serialize object first
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
