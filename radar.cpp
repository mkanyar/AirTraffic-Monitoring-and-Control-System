#include "radar.h"
#include <algorithm>
radar::radar()
{
}

radar::~radar()
{
}

/*void radar::hit(aircraft ac){
	this->hit_list.push_back(ac);
}*/

void radar::readInput(){
	int airplane_schedule[160] = {
		0, -641, 283, 500, 95000, 101589, 10000, 13,
		1, -223, -630, -526, 71000, 100000, 13000, 16,
		-1, -180, -446, -186, 41000, 100000, 6000, 31,
		3, 474, -239, 428, 38000, 0, 14000, 44,
		-1, -535, 520, 360, 95000, 100000, 1000, 49,
		-1, -164, -593, -501, 83000, 100000, 12000, 67,
		6, 512, 614, 520, 86000, -1571, 9000, 87,
		7, -275, 153, -399, 47000, 100000, 12000, 103,
		8, -129, 525, -300, 92000, 100000, 1000, 123,
		9, 437, 574, 339, 32000, 0, 8000, 129,
		10, 568, 538, 192, 50000, 0, 4000, 133,
		11, 347, 529, -599, 83000, -1799, 10000, 140,
		12, -512, -482, 578, 35000, 100000, 4000, 142,
		13, 619, -280, 194, 74000, 0, 10000, 157,
		14, -141, 427, -321, 41000, 102251, 11000, 165,
		15, -199, 242, -205, 56000, 100000, 4000, 172,
		16, 315, -197, -365, 77000, 0, 1000, 187,
		17, -138, 455, 602, 23000, 102290, 14000, 199,
		18, -150, 557, -356, 38000, 100000, 1000, 204,
		19, 194, 184, 598, 35000, 0, 2000, 221,
		};

/*	for (unsigned int i = 0; i < airplane_schedule.size(); ){
		for(unsigned int j = 0; j < airplane_schedule.size(); j++){
			switch(j) {
				case j == 0:
					$this->hit_list[i].setID(airplace_schedule[j]);
					break;
				case j%1 == 0:
					$this->hit_list[i].setSpeedX(airplace_schedule[j]);
					break;
				case j%2 == 0:
					$this->hit_list[i].setSpeedX(airplace_schedule[j]);
					break;
				default:
			    // code block
			}

			if (j%7 == 0){i++;}
		}
	}*/
}

//display all the hits in the input file
/*void radar::printHitList(){
	cout << "Airspace Hits: " << endl;
	for (unsigned int i = 0; i < hit_list.size(); i++){
		cout << "Aircraft ID: " << hit_list[i].getID() << endl;
		cout << "X: " << hit_list[i].getX() << " Y: " << hit_list[i].getY() << " Z: " << hit_list[i].getZ() << endl;
		cout << "SpeedX: " << hit_list[i].getSpeedX() << " SpeedY: " << hit_list[i].getSpeedY() << " SpeedZ: " << hit_list[i].getSpeedZ() << endl;
	}

}*/
void radar::printAll(){
	cout << "Airspace Hits: " << endl;
	for (unsigned int i = 0; i < GLOBAL_AIRCRAFT_LIST.size(); i++){
		cout << "Aircraft ID: " << GLOBAL_AIRCRAFT_LIST[i]->getID() << endl;
		cout << "X: " << GLOBAL_AIRCRAFT_LIST[i]->getX() << " Y: " << GLOBAL_AIRCRAFT_LIST[i]->getY() << " Z: " << GLOBAL_AIRCRAFT_LIST[i]->getZ() << endl;
		cout << "SpeedX: " << GLOBAL_AIRCRAFT_LIST[i]->getSpeedX() << " SpeedY: " << GLOBAL_AIRCRAFT_LIST[i]->getSpeedY() << " SpeedZ: " << GLOBAL_AIRCRAFT_LIST[i]->getSpeedZ() << endl;
	}

}

void radar::populateEntered (){
	//every second
	for (unsigned int i = 0; i < GLOBAL_AIRCRAFT_LIST.size(); i++){
		if (GLOBAL_AIRCRAFT_LIST[i]->activate(bufferString) && std::find(entered_list.begin(), entered_list.end(), GLOBAL_AIRCRAFT_LIST[i])==entered_list.end()){
			//hit_list.erase(hit_list.begin() + i);
			entered_list.push_back(GLOBAL_AIRCRAFT_LIST[i]);
		}
	}
}
//narrow down hit_list to active_list that are within airspace

void* radar::populateAirspace(void* arg){
	while(true){

		auto start = std::chrono::system_clock::now();
		//cout << "entered list size -> "<< entered_list.size()<<endl;
		//vector here
		for (unsigned int i = 0; i< entered_list.size(); i++){
			if((entered_list[i]->getX() >= lowerX && entered_list[i]->getX() <= upperX) &&
					(entered_list[i]->getY() >= lowerY && entered_list[i]->getY() <= upperY) &&
					(entered_list[i]->getZ() >= lowerZ && entered_list[i]->getZ() <= upperZ)){
				if(std::find(airspace.begin(), airspace.end(), entered_list[i])==airspace.end()){
				//entered_list.erase(entered_list.begin() + i);
				airspace.push_back(entered_list[i]);
				while(pthread_mutex_lock( &buffstr )!=0);
				bufferString+= "Time: " + to_string(GLOBAL_CLOCK)+"| Aircraft "+to_string(entered_list[i]->getID())+" entered airspace\n";
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
		//cout << "Execution time is  "<<(chrono::duration_cast<chrono::milliseconds>(end - start).count())<<endl;
		usleep(15000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}

void* radar::populateBuffer(void* arg){

	while(true){
		auto start = std::chrono::system_clock::now();
		stringstream ss;

		while(pthread_mutex_lock( &a_space )!=0);

		for (unsigned int i = 0; i < airspace.size(); i++){

			if(airspace[i]->getID()==-1){
				if(fmodf((float)GLOBAL_CLOCK,15.0)==0.0){
					ss 	<< "Time: " << GLOBAL_CLOCK
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
//				cout <<"BOOL-> "<< to_string() <<endl;
//				cout << " "<<to_string(!(airspace[i]->getZ()>=lowerZ && airspace[i]->getZ() <= upperZ))<<endl;
//				cout << airspace[i]->getID()<<" "<<GLOBAL_CLOCK<<endl;

				if(!((airspace[i]->getX() >= lowerX && airspace[i]->getX() <= upperX) &&
					 (airspace[i]->getY() >= lowerY && airspace[i]->getY() <= upperY) &&
					 (airspace[i]->getZ() >= lowerZ && airspace[i]->getZ() <= upperZ))
				)

				{
					//cout << airspace[i]->getID()<<" "<<GLOBAL_CLOCK<<endl;
					comm::hitScan(airspace[i]);
				}
				else{

				ss 	<< "Time: " << GLOBAL_CLOCK
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
		//cout << "Execution time is  "<<(chrono::duration_cast<chrono::milliseconds>(end - start).count())<<endl;
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

