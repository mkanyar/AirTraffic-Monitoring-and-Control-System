/*
 * ATC.cpp
 *
 */

#include "ATC.h"
#include "trackfile.h"
#include <chrono>

ATC::ATC() {
}
ATC::ATC(vector<aircraft*> aircraftlist){
	airspace=aircraftlist;
}
void ATC::Collision_handling(aircraft* a1, aircraft* a2){

	float i = 0.03;
		float j = 3;
		bool switchturn = false;

		int nowclock = GLOBAL_CLOCK;

		int savea1x = a1->getSpeedX();
		int savea2x = a2->getSpeedX();
		int savea1y = a1->getSpeedY();
		int savea2y = a2->getSpeedY();

		while (collision(a1, a2)){
			a1->setSpeedX(a2->getSpeedX()*i);
			a1->setSpeedY(a2->getSpeedY()*i);
			a2->setSpeedX(a2->getSpeedX()*j);
			a2->setSpeedY(a2->getSpeedY()*j);
			if(i>0)
				i = i * 0.1;
			break;
		}
		while(nowclock == GLOBAL_CLOCK);
		a1->setSpeedX(savea1x);
		a2->setSpeedX(savea2x);
		a1->setSpeedY(savea1y);
		a2->setSpeedY(savea2y);
}

void* ATC::Collision_detection(void* arg){

	while(true){
	auto start = std::chrono::system_clock::now();
	string collision_message;
	pthread_mutex_lock( &a_space );
	for(unsigned int i =0;i<airspace.size();i++){
		for(unsigned int j =0;j<airspace.size();j++){
			if(i!=j){
				if(airspace[i]->getID() != -1 || airspace[j]->getID() != -1){
					if(collision(airspace[i],airspace[j]))
					{
						Collision_handling(airspace[i],airspace[j]);

					}
				}
			}
		}
	}
	pthread_mutex_unlock( &a_space );
	auto end =  std::chrono::system_clock::now();
	usleep(5000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}



ATC::~ATC() {
	// TODO Auto-generated destructor stub
}

