#include "radar.h"

//extern string from radar.h
string bufferString;

radar::radar()
{
}

radar::~radar()
{
}

void radar::hit(aircraft ac){
	this->hit_list.push_back(ac);
}

void radar::readInputFile(){

	ifstream infile;

	infile.open("inputs.txt");

		if (!infile) {

			cout << "Unable to open file" << endl;

			exit(1);
		}

		while (infile) {

		getline(infile, temp_id, ',');

		getline(infile, temp_speed_x, ',');

		getline(infile, temp_speed_y, ',');

		getline(infile, temp_speed_z, ',');

		getline(infile, temp_x, ',');

		getline(infile, temp_y, ',');

		getline(infile, temp_z, ',');

		getline(infile, temp_time, ',');

		//aircraft ac(stoi(temp_id), stoi(temp_speed_x),stoi(temp_speed_y),stoi(temp_speed_z),stoi(temp_x),stoi(temp_y),stoi(temp_z),stoi(temp_time));

		//hit_list.push_back(ac);

			if (infile.eof()){
				break;
			}
		}
}

//display all the hits in the input file
void radar::printHitList(){
	cout << "Airspace Hits: " << endl;
	for (unsigned int i = 0; i < hit_list.size(); i++){
		cout << "Aircraft ID: " << hit_list[i].getID() << endl;
		cout << "X: " << hit_list[i].getX() << " Y: " << hit_list[i].getY() << " Z: " << hit_list[i].getZ() << endl;
		cout << "SpeedX: " << hit_list[i].getSpeedX() << " SpeedY: " << hit_list[i].getSpeedY() << " SpeedZ: " << hit_list[i].getSpeedZ() << endl;
	}

}

//narrow down hit_list to active_list that are within airspace
void radar::checkActive(int time){
	for (unsigned int i = 0; i< hit_list.size(); i++){
		if (hit_list[i].getTime() <= time && hit_list[i].getID() != -1){
			if((hit_list[i].getX() >= lowerX && hit_list[i].getX() <= upperX) &&
				(hit_list[i].getY() >= lowerY && hit_list[i].getY() <= upperY) &&
				(hit_list[i].getZ() >= lowerZ && hit_list[i].getZ() <= upperZ)){

			aircraft ac(hit_list[i].getID(),
						hit_list[i].getX(),
						hit_list[i].getY(),
						hit_list[i].getZ(),
						hit_list[i].getSpeedX(),
						hit_list[i].getSpeedY(),
						hit_list[i].getSpeedZ(),
						hit_list[i].getTime()
						);

			//hit_list.erase(hit_list.begin() + i);
			active_list.push_back(ac);
			}
		}
	}
}

void radar::populateBuffer(){

	stringstream ss;

	for (unsigned int i = 0; i < active_list.size(); i++){
		ss << active_list[i].getID() << ","
		   << active_list[i].getSpeedX() << ","
		   << active_list[i].getSpeedY() << ","
		   << active_list[i].getSpeedZ() << ","
		   << active_list[i].getX() << ","
		   << active_list[i].getY() << ","
		   << active_list[i].getZ() << ","
		   << active_list[i].getTime() << "\n";
	}

	bufferString += ss.str();
}

void radar::printActive(){
	cout << "Active List: " << endl;
	for (unsigned int i = 0; i < active_list.size(); i++){
		cout << "Aircraft ID: " << active_list[i].getID() << endl;
		cout << "X: " << active_list[i].getX() << " Y: " << active_list[i].getY() << " Z: " << active_list[i].getZ() << endl;
		cout << "SpeedX: " << active_list[i].getSpeedX() << " SpeedY: " << active_list[i].getSpeedY() << " SpeedZ: " << active_list[i].getSpeedZ() << endl;

	}
}


