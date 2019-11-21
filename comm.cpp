#include "comm.h"

using namespace std;
/*NOTE: I think these attributes are for aircrafts only*/
    //string comm:: getID(){return this->ID;};
    //float comm::getX(){return this->x;}
   	//float comm::getY(){return y;};
   	//float comm::getZ(){return z;};

//   	float comm::getSpeedX(){return speed_x;};
//   	float comm::getSpeedY(){return speed_y;};
//   	float comm::getSpeedZ(){return speed_z;};
//   	float comm::getEntryTime(){return entry_time;};
//   	void comm::changeSpeed(float x,float y,float z)
//   	{
//   	speed_x=x;
//   	speed_y=y;
//   	speed_z=z;
//   	}

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
   		int ovalORholding = 0;


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
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " now has altitude equal to " + to_string(givenAltitude) + "\n";
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
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " now has velocity equal to: (Vx,Vy,Vz) = ("+to_string(T2)+","+to_string(T3)+","+to_string(T4)+")\n";
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
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " is now pointed towards (x,y) = ("+to_string(T2)+","+to_string(T3)+")\n";
   				}
   			}
   		}

   		else if(TaskNumberInt == 4){
   			ID = T1;
   			ovalORholding = T2;
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					if(ovalORholding == 0){
   						airspace[i]->OVAL = true;
   						bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " entered OVAL state \n";
   					}
   					else{
   						airspace[i]->OVAL = false;
   						bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " entered HOLDING state\n";
   					}
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
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " left its pattern \n";
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
   					cout << "Aircraft ID:" + ID << endl;
   					cout << "Entry Time: " + to_string(airspace[i]->getTime())<< endl;
   					cout << "x-coordinate: " + to_string(airspace[i]->getX()) << endl;
   					cout << "y-coordinate: " + to_string(airspace[i]->getY()) << endl;
   					cout << "z-coordinate: " + to_string(airspace[i]->getZ()) << endl;
   					cout << "x-speed: " + to_string(airspace[i]->getSpeedX()) << endl;
   					cout << "y-speed: " + to_string(airspace[i]->getSpeedY()) << endl;
   					cout << "z-speed: " + to_string(airspace[i]->getSpeedZ()) << endl;
   					bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(ID) + " status acquired \n";
   				}
   			}
   		}
   		else if(TaskNumberInt == 7){
   			ovalORholding = T1;
   			if(ovalORholding == 0){
   				GLOBAL_OVAL = true;
   				bufferString+= to_string(GLOBAL_CLOCK) + " All aircrafts have entered entered OVAL state \n";
   			}
   			else{
   				GLOBAL_OVAL = false;
   				bufferString+= to_string(GLOBAL_CLOCK) + " All aircrafts have entered HOLDING state\n";
   			}
   		}
   		//CHECK FOR ACCURACY OF THE COMMAND RELATIVE TO THE TASK ASKED TO DO
   		else if(TaskNumberInt == 8){
   			GLOBAL_OVAL = false;
   			bufferString+= to_string(GLOBAL_CLOCK) + "All aircrafts left their patterns\n";
   		}
   		else{
   			for(int i = 0; i < airspace.size(); i++){
   				cout << "Aircraft ID:" + ID << endl;
   				cout << "Entry Time: " + to_string(airspace[i]->getTime())<< endl;
   				cout << "x-coordinate: " + to_string(airspace[i]->getX()) << endl;
   				cout << "y-coordinate: " + to_string(airspace[i]->getY()) << endl;
   				cout << "z-coordinate: " + to_string(airspace[i]->getZ()) << endl;
   				cout << "x-speed: " + to_string(airspace[i]->getSpeedX()) << endl;
   				cout << "y-speed: " + to_string(airspace[i]->getSpeedY()) << endl;
   				cout << "z-speed: " + to_string(airspace[i]->getSpeedZ()) << endl;
   				bufferString+= to_string(GLOBAL_CLOCK) + " All aircrafts' statuses acquired \n";
   			}
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

   	void comm::hitScan(vector <aircraft> hitlist){
   		for(int i = 0; i < airspace.size(); i++){
   			stringstream transformID1(airspace[i]->getID());
   			int planeID;
   			transformID1 >> planeID;

   			bool found = false;

   			for(int j = 0; j < hitlist.size(); j++){
   				stringstream transformID2(hitlist[j].getID());
   				int hitlistID;
   				transformID2 >> hitlistID;
   				if(planeID == hitlistID) {
   					found = true;
   					break;
   				}
   			}
   			if(!found){
   				bufferString+= to_string(GLOBAL_CLOCK) + " Aircraft with ID " + to_string(planeID) + " left airspace, no hit on it \n";
   			}
   		}

   		//airspace = hitlist;

   		bufferString+= to_string(GLOBAL_CLOCK) + " Hit list processed. \n";
   	}



comm::comm()
{
}

comm::~comm()
{
}
