#include "radar.h"
#include <algorithm>
radar::radar()
{
}

radar::~radar()
{
}


void radar::printAll(){
	cout << "Airspace Hits: " << endl;
	for (unsigned int i = 0; i < GLOBAL_AIRCRAFT_LIST.size(); i++){
		cout << "Aircraft ID: " << GLOBAL_AIRCRAFT_LIST[i]->getID() << endl;
		cout << "X: " << GLOBAL_AIRCRAFT_LIST[i]->getX() << " Y: " << GLOBAL_AIRCRAFT_LIST[i]->getY() << " Z: " << GLOBAL_AIRCRAFT_LIST[i]->getZ() << endl;
		cout << "SpeedX: " << GLOBAL_AIRCRAFT_LIST[i]->getSpeedX() << " SpeedY: " << GLOBAL_AIRCRAFT_LIST[i]->getSpeedY() << " SpeedZ: " << GLOBAL_AIRCRAFT_LIST[i]->getSpeedZ() << endl;
	}

}

//populates the entered_list vectors with aircraft that have entry time past the current global clock every second
void radar::populateEntered (){
	for (unsigned int i = 0; i < GLOBAL_AIRCRAFT_LIST.size(); i++){
		if (GLOBAL_AIRCRAFT_LIST[i]->activate(bufferString) && std::find(entered_list.begin(), entered_list.end(), GLOBAL_AIRCRAFT_LIST[i])==entered_list.end()){
			entered_list.push_back(GLOBAL_AIRCRAFT_LIST[i]);
		}
	}
}

//narrow down entered_list to active_list that are within the coordinates of the airspace every 15 seconds
void* radar::populateAirspace(void* arg){
	while(true){
		auto start = std::chrono::system_clock::now();

		for (unsigned int i = 0; i< entered_list.size(); i++){
			if((entered_list[i]->getX() >= lowerX && entered_list[i]->getX() <= upperX) &&
					(entered_list[i]->getY() >= lowerY && entered_list[i]->getY() <= upperY) &&
					(entered_list[i]->getZ() >= lowerZ && entered_list[i]->getZ() <= upperZ)){
				if(std::find(airspace.begin(), airspace.end(), entered_list[i])==airspace.end()){
				airspace.push_back(entered_list[i]);
				while(pthread_mutex_lock( &buffstr )!=0);
				bufferString += "ENTRY|Time: " + to_string(GLOBAL_CLOCK)+"| Aircraft "+to_string(entered_list[i]->getID())+" entered airspace\n";
				pthread_mutex_unlock( &buffstr );
				}
			}
			else{
				if(std::find(airspace.begin(), airspace.end(), entered_list[i])!=airspace.end()){
					comm::hitScan(entered_list[i]);
				}
			}
		}

		auto end =  std::chrono::system_clock::now();
		usleep(15000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}

//populate the buffer to use for displaying and writing to the history log
void* radar::populateBuffer(void* arg){
	while(true){
		auto start = std::chrono::system_clock::now();
		stringstream ss;

		while(pthread_mutex_lock( &a_space )!=0);

		for (unsigned int i = 0; i < airspace.size(); i++){

			if(airspace[i]->getID()==-1){
				if(fmodf((float)GLOBAL_CLOCK,15.0)==0.0){
					ss 	<< "SCAN|Time: " << GLOBAL_CLOCK
						<< "| ID: " << airspace[i]->getID()
						<< ", Vx: " << airspace[i]->getSpeedX()
						<< ", Vy: " << airspace[i]->getSpeedY()
						<< ", Vz: " << airspace[i]->getSpeedZ()
						<< ", X: "  << airspace[i]->getX()
						<< ", Y: "  << airspace[i]->getY()
						<< ", Z: "  << airspace[i]->getZ()
						<< "\n";
				}
			}
			else{

				if(!((airspace[i]->getX() >= lowerX && airspace[i]->getX() <= upperX) &&
					 (airspace[i]->getY() >= lowerY && airspace[i]->getY() <= upperY) &&
					 (airspace[i]->getZ() >= lowerZ && airspace[i]->getZ() <= upperZ))
				)

				{
					comm::hitScan(airspace[i]);
				}
				else{

				ss 	<< "SCAN|Time: " << GLOBAL_CLOCK
					<< "| ID: " << airspace[i]->getID()
					<< ", Vx: " << airspace[i]->getSpeedX()
					<< ", Vy: " << airspace[i]->getSpeedY()
					<< ", Vz: " << airspace[i]->getSpeedZ()
					<< ", X: "  << airspace[i]->getX()
					<< ", Y: "  << airspace[i]->getY()
					<< ", Z: "  << airspace[i]->getZ()
					<< "\n";
				}
			}
		}

		pthread_mutex_unlock( &a_space );

		while(pthread_mutex_lock( &buffstr )!=0);
		bufferString += ss.str();
		pthread_mutex_unlock( &buffstr );
		auto end =  std::chrono::system_clock::now();
		usleep(5000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}

}

void radar::printActive(){
	cout << "Active List: " << endl;
	for (unsigned int i = 0; i < airspace.size(); i++){
		cout << "Aircraft ID: " << airspace[i]->getID()
		<< "\n"
		<< "X: " << airspace[i]->getX()
		<< " Y: " << airspace[i]->getY()
		<< " Z: " << airspace[i]->getZ()
		<< "\n"
		<< "SpeedX: " << airspace[i]->getSpeedX()
		<< " SpeedY: " << airspace[i]->getSpeedY()
		<< " SpeedZ: " << airspace[i]->getSpeedZ()
		<< "\n";

	}
}

