#include "comm.h"

using namespace std;
//operator commands only
   	void comm::receiveMessage(vector <string> tokens){
   		string TaskNumber = tokens[0];
   		stringstream transform(TaskNumber);
   		int T1 = 0;
   		int T2 = 0;
   		int T3 = 0;
   		int T4 = 0;

   		//Four tokens at max.
   		if(tokens.size() == 1){
   			stringstream transform1(tokens[1]);
   			transform1 >> T1;
   		}
   		else if(tokens.size() == 2){
   			stringstream transform1(tokens[1]);
   			stringstream transform2(tokens[2]);
   			transform1 >> T1;
   			transform2 >> T2;
   		}
   		else if(tokens.size() == 3){
   			stringstream transform1(tokens[1]);
   			stringstream transform2(tokens[2]);
   			stringstream transform3(tokens[3]);
   			transform1 >> T1;
   			transform2 >> T2;
   			transform3 >> T3;
   		}
   		else{
   			stringstream transform1(tokens[1]);
   			stringstream transform2(tokens[2]);
   			stringstream transform3(tokens[3]);
   			stringstream transform4(tokens[4]);
   			transform1 >> T1;
   			transform2 >> T2;
   			transform3 >> T3;
   			transform4 >> T4;
   		}

   		int ID = 0;
   		int givenAltitude = 0;
   		int x = 0;
   		int y = 0;
   		int z = 0;


   		int TaskNumberInt = 0;
   		transform >> TaskNumberInt;

   		if(TaskNumberInt == 1){
   			ID = T1;
   			givenAltitude = T2;

   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->setZ(givenAltitude);
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(airspace[i]->getID()) + " now has altitude equal to " + to_string(givenAltitude) + "\n";
   				}
   			}
   		}
   		else if(TaskNumberInt == 2){
   			ID = T1;
   			x = T2;
   			y = T3;
   			z = T4;
   			int currentID;

   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->setSpeedX(x);
   					airspace[i]->setSpeedY(y);
   					airspace[i]->setSpeedZ(z);
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(airspace[i]->getID()) + " now has velocity equal to: (Vx,Vy,Vz) = ("+to_string(T2)+","+to_string(T3)+","+to_string(T4)+")\n";
   					break;
   				}
   			}
   		}
   		else if(TaskNumberInt == 3){
   			ID = T1;
   			x = T2;
   			y = T3;

   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->setX(x);
   					airspace[i]->setY(y);
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(airspace[i]->getID()) + " is now pointed towards (x,y) = ("+to_string(T2)+","+to_string(T3)+")\n";
   				}
   			}
   		}

   		else if(TaskNumberInt == 4){
   			ID = T1;
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->OVAL = true;
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(airspace[i]->getID()) + " entered OVAL/HOLDING state \n";
   				}
   			}
   		}

   		//NOT IMPLEMENTED YET FOR OVAL/HOLDING
   		else if(TaskNumberInt == 5){
   			ID = T1;

   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->OVAL = false;
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(airspace[i]->getID()) + " left its OVAL/HOLDING pattern \n";
   				}
   			}
   		}
   		else if(TaskNumberInt == 6){
   			ID = T1;
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					cout << "Aircraft ID: " + to_string(airspace[i]->getID()) << endl;
   					cout << "Entry Time: " + to_string(airspace[i]->getTime())<< endl;
   					cout << "x-coordinate: " + to_string(airspace[i]->getX()) << endl;
   					cout << "y-coordinate: " + to_string(airspace[i]->getY()) << endl;
   					cout << "z-coordinate: " + to_string(airspace[i]->getZ()) << endl;
   					cout << "x-speed: " + to_string(airspace[i]->getSpeedX()) << endl;
   					cout << "y-speed: " + to_string(airspace[i]->getSpeedY()) << endl;
   					cout << "z-speed: " + to_string(airspace[i]->getSpeedZ()) << endl;
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(airspace[i]->getID()) + " status acquired \n";
   				}
   			}
   		}
   		else if(TaskNumberInt == 7){
   			GLOBAL_OVAL = true;
   			bufferString+= to_string(GLOBAL_CLOCK) + " All aircrafts have entered entered OVAL/HOLDING state \n";
   		}
   		//CHECK FOR ACCURACY OF THE COMMAND RELATIVE TO THE TASK ASKED TO DO
   		else if(TaskNumberInt == 8){
   			GLOBAL_OVAL = false;
   			bufferString+= to_string(GLOBAL_CLOCK) + "All aircrafts left their patterns\n";
   		}
   		else{
   			for(int i = 0; i < airspace.size(); i++){
   				cout << "Aircraft ID: " + to_string(airspace[i]->getID()) << endl;
   				cout << "Entry Time: " + to_string(airspace[i]->getTime())<< endl;
   				cout << "x-coordinate: " + to_string(airspace[i]->getX()) << endl;
   				cout << "y-coordinate: " + to_string(airspace[i]->getY()) << endl;
   				cout << "z-coordinate: " + to_string(airspace[i]->getZ()) << endl;
   				cout << "x-speed: " + to_string(airspace[i]->getSpeedX()) << endl;
   				cout << "y-speed: " + to_string(airspace[i]->getSpeedY()) << endl;
   				cout << "z-speed: " + to_string(airspace[i]->getSpeedZ()) << endl;
   			}
   			bufferString+= to_string(GLOBAL_CLOCK) + " All aircrafts' statuses acquired \n";
   		}
   	}


   	void comm::deletePlane(int ID){
   		for(int i = 0; i < airspace.size(); i++){
   			stringstream transformID(airspace[i]->getID());
   			int currentID;
   			transformID >> currentID;
   			if(currentID == ID) {
   				bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " left airspace \n";
   				airspace.erase(airspace.begin()+i);
   				break;
   			}
   		}
   	}

   	void comm::hitScan(aircraft* hitobject){
   		for(int i = 0; i < airspace.size(); i++){
   			if(airspace[i]==hitobject){
   				while(pthread_mutex_lock( &buffstr )!=0);
   				bufferString+= to_string(GLOBAL_CLOCK) + " aircraft with ID " + to_string(airspace[i]->getID()) + " left airspace\n";
   				pthread_mutex_unlock( &buffstr );
   				airspace.erase(airspace.begin()+i);
   			}
   		}
   	}



comm::comm()
{
}

comm::~comm()
{
}
