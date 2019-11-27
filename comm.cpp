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
   		int T5 = 0;
		int T6 = 0;
		int T7 = 0;

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
   		else if(tokens.size() == 4){
			stringstream transform1(tokens[1]);
			stringstream transform2(tokens[2]);
			stringstream transform3(tokens[3]);
			stringstream transform4(tokens[4]);
			transform1 >> T1;
			transform2 >> T2;
			transform3 >> T3;
			transform4 >> T4;
		}
   		else if(tokens.size() == 5){
   			stringstream transform1(tokens[1]);
			stringstream transform2(tokens[2]);
			stringstream transform3(tokens[3]);
			stringstream transform4(tokens[4]);
			stringstream transform5(tokens[5]);
			transform1 >> T1;
			transform2 >> T2;
			transform3 >> T3;
			transform4 >> T4;
			transform5 >> T5;
		}
   		else if(tokens.size() == 6){
   			stringstream transform1(tokens[1]);
			stringstream transform2(tokens[2]);
			stringstream transform3(tokens[3]);
			stringstream transform4(tokens[4]);
			stringstream transform5(tokens[5]);
			stringstream transform6(tokens[6]);
			transform1 >> T1;
			transform2 >> T2;
			transform3 >> T3;
			transform4 >> T4;
			transform5 >> T5;
			transform6 >> T6;
		}
   		else{
   			stringstream transform1(tokens[1]);
			stringstream transform2(tokens[2]);
			stringstream transform3(tokens[3]);
			stringstream transform4(tokens[4]);
			stringstream transform5(tokens[5]);
			stringstream transform6(tokens[6]);
			stringstream transform7(tokens[7]);
			transform1 >> T1;
			transform2 >> T2;
			transform3 >> T3;
			transform4 >> T4;
			transform5 >> T5;
			transform6 >> T6;
			transform7 >> T7;
   		}

   		int ID = 0;
   		int givenAltitude = 0;
   		int x = 0;
   		int y = 0;
   		int z = 0;
   		int Vx = 0;
   		int Vy = 0;
   		int Vz = 0;
   		int projectTime = 0;


   		int TaskNumberInt = 0;
   		transform >> TaskNumberInt;

   		if(TaskNumberInt == 1){
   			ID = T1;
   			givenAltitude = T2;

   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;

   				if(currentID == ID) {
   					airspace[i]->setZ(givenAltitude);
   					cout << "RESPONSE|" << "Time: " + to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << " now has altitude equal to " << to_string(givenAltitude) << "\n";
   					while(pthread_mutex_lock( &buffstr )!=0);
   					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " now has altitude equal to " + to_string(givenAltitude) + "\n";
   					pthread_mutex_unlock( &buffstr );
   					break;
   				}
   			}
   			pthread_mutex_unlock( &a_space );
   		}

   		else if(TaskNumberInt == 2){
   			ID = T1;
   			x = T2;
   			y = T3;
   			z = T4;
   			int currentID;

   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;

   				if(currentID == ID) {
   					airspace[i]->setSpeedX(x);
   					airspace[i]->setSpeedY(y);
   					airspace[i]->setSpeedZ(z);
   					cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << " now has velocity equal to: (Vx,Vy,Vz) = (" << to_string(T2) << "," << to_string(T3) << "," << to_string(T4) << ")\n";
   					while(pthread_mutex_lock( &buffstr )!=0);
   					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " now has velocity equal to: (Vx,Vy,Vz) = ("+to_string(T2)+","+to_string(T3)+","+to_string(T4)+")\n";
   					pthread_mutex_unlock( &buffstr );
   					break;
   				}
   			}
   			pthread_mutex_unlock( &a_space );
   		}
   		else if(TaskNumberInt == 3){
   			ID = T1;
   			x = T2;
   			y = T3;

   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->setX(x);
   					airspace[i]->setY(y);
   					cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << " is now pointed towards (x,y) = (" << to_string(T2) << "," << to_string(T3) << ")\n";
   					while(pthread_mutex_lock( &buffstr )!=0);
   					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " is now pointed towards (x,y) = ("+to_string(T2)+","+to_string(T3)+")\n";
   					pthread_mutex_unlock( &buffstr );
   					break;
   				}
   			}
   			pthread_mutex_unlock( &a_space );
   		}

   		else if(TaskNumberInt == 4){
   			ID = T1;
   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->OVAL = true;
   					cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << " entered holding state \n";
   					while(pthread_mutex_lock( &buffstr )!=0);
   					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " entered holding state \n";
   					pthread_mutex_unlock( &buffstr );
   					break;
   				}
   			}
   			pthread_mutex_unlock( &a_space );
   		}

   		else if(TaskNumberInt == 5){
   			ID = T1;

   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					airspace[i]->OVAL = false;
   					cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << " left its holding pattern \n";
   					while(pthread_mutex_lock( &buffstr )!=0);
   					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " left its holding pattern \n";
   					pthread_mutex_unlock( &buffstr );
   					break;
   				}
   			}
   			pthread_mutex_unlock( &a_space );
   		}
   		else if(TaskNumberInt == 6){
   			ID = T1;
   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				stringstream transformID(airspace[i]->getID());
   				int currentID;
   				transformID >> currentID;
   				if(currentID == ID) {
   					cout << "Aircraft ID: " + to_string(airspace[i]->getID()) << endl;
   					cout << "Entry Time: " + to_string(airspace[i]->getTime())<< endl;
   					cout << "X: " + to_string(airspace[i]->getX()) << endl;
   					cout << "Y: " + to_string(airspace[i]->getY()) << endl;
   					cout << "Z: " + to_string(airspace[i]->getZ()) << endl;
   					cout << "Vx: " + to_string(airspace[i]->getSpeedX()) << endl;
   					cout << "Vy: " + to_string(airspace[i]->getSpeedY()) << endl;
   					cout << "Vz: " + to_string(airspace[i]->getSpeedZ()) << endl;

   					cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << ", status acquired \n";
   					while(pthread_mutex_lock( &buffstr )!=0);
   					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + ", status acquired \n";
   					pthread_mutex_unlock( &buffstr );
   					break;
   				}
   			}
   			pthread_mutex_unlock( &a_space );
   		}
   		else if(TaskNumberInt == 7){
   			GLOBAL_OVAL = true;
   			cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| All aircrafts have entered entered holding pattern (enter any key) \n";
   			while(pthread_mutex_lock( &buffstr )!=0);
   			bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| All aircrafts have entered entered holding pattern (enter any key) \n";
   			pthread_mutex_unlock( &buffstr );
   		}
   		//CHECK FOR ACCURACY OF THE COMMAND RELATIVE TO THE TASK ASKED TO DO
   		else if(TaskNumberInt == 8){
   			GLOBAL_OVAL = false;
   			cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| All aircrafts left their holding patterns\n";
   			while(pthread_mutex_lock( &buffstr )!=0);
   			bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| All aircrafts left their holding patterns\n";
   			pthread_mutex_unlock( &buffstr );
   		}
   		else if(TaskNumberInt == 9){ //add aircraft
   			ID = T1;
   			Vx = T2;
   			Vy = T3;
   			Vz = T4;
   			x = T5;
   			y = T6;
   			z = T7;

   			while(pthread_mutex_lock( &e_list )!=0);
   			GLOBAL_AIRCRAFT_LIST.push_back(new aircraft(ID, Vx, Vy, Vz, x, y, z, GLOBAL_CLOCK));
   			pthread_mutex_unlock( &e_list );
   			cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| New aircraft with ID " << to_string(ID) << " created\n";
   			while(pthread_mutex_lock( &buffstr )!=0);
			bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| New aircraft with ID " + to_string(ID) + " created\n";;
			pthread_mutex_unlock( &buffstr );

   		}
   		else if(TaskNumberInt == 10){ //delete aircraft
   			ID = T1;

   			while(pthread_mutex_lock( &a_space )!=0);
   			cout <<"HELLO" <<endl;
			for(int i = 0; i < airspace.size(); i++){
				cout <<"BYE" <<endl;
				if(airspace[i]->getID() == ID) {
					airspace.erase(airspace.begin()+i);
					break;
				}
			}
			pthread_mutex_unlock( &a_space );

			while(pthread_mutex_lock( &e_list )!=0);
			for(int i = 0; i < entered_list.size(); i++){
				if(entered_list[i]->getID() == ID) {
					entered_list.erase(entered_list.begin()+i);
					break;
				}
			}
			pthread_mutex_unlock( &e_list );

			for(int i = 0; i < GLOBAL_AIRCRAFT_LIST.size(); i++){
				if(GLOBAL_AIRCRAFT_LIST[i]->getID() == ID) {
					GLOBAL_AIRCRAFT_LIST.erase(GLOBAL_AIRCRAFT_LIST.begin()+i);
					break;
				}
			}

   			cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Deleted aircraft with ID " << to_string(ID) << "\n";
			while(pthread_mutex_lock( &buffstr )!=0);
			bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Deleted aircraft with ID " + to_string(ID) + "\n";;
			pthread_mutex_unlock( &buffstr );
   		}
   		else if(TaskNumberInt == 11){ //project position
   			ID = T1;
   			projectTime = T2;

   			int currentID;

			while(pthread_mutex_lock( &a_space )!=0);
			for(int i = 0; i < airspace.size(); i++){
				stringstream transformID(airspace[i]->getID());
				int currentID;
				transformID >> currentID;

				if(currentID == ID) {

					int projectX = airspace[i]->getX()+(airspace[i]->getSpeedX()*projectTime);
					int projectY = airspace[i]->getY()+(airspace[i]->getSpeedY()*projectTime);
					int projectZ = airspace[i]->getZ()+(airspace[i]->getSpeedZ()*projectTime);

					cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(airspace[i]->getID()) << " will be at position = (" << to_string(projectX) << "," << to_string(projectY) << "," << to_string(projectZ) << ") in " << to_string(projectTime) << " seconds\n";
					while(pthread_mutex_lock( &buffstr )!=0);
					bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " will be at position = ("+to_string(projectX)+","+to_string(projectY)+","+to_string(projectZ)+") in " + to_string(projectTime) + " seconds\n";
					pthread_mutex_unlock( &buffstr );
					break;
				}
			}
			pthread_mutex_unlock( &a_space );

   		}
   		else{
   			while(pthread_mutex_lock( &a_space )!=0);
   			for(int i = 0; i < airspace.size(); i++){
   				cout << "Aircraft ID: " + to_string(airspace[i]->getID()) << endl;
   				cout << "Entry Time: " + to_string(airspace[i]->getTime())<< endl;
   				cout << "X: " + to_string(airspace[i]->getX()) << endl;
   				cout << "Y: " + to_string(airspace[i]->getY()) << endl;
   				cout << "Z: " + to_string(airspace[i]->getZ()) << endl;
   				cout << "Vx: " + to_string(airspace[i]->getSpeedX()) << endl;
   				cout << "Vy: " + to_string(airspace[i]->getSpeedY()) << endl;
   				cout << "Vz: " + to_string(airspace[i]->getSpeedZ()) << endl;
   			}
   			pthread_mutex_unlock( &a_space );
   			cout << "RESPONSE|" << "Time: " << to_string(GLOBAL_CLOCK) << "| All aircrafts' statuses acquired \n";
   			while(pthread_mutex_lock( &buffstr )!=0);
   			bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| All aircrafts' statuses acquired \n";
   			pthread_mutex_unlock( &buffstr );
   		}
   	}

   	void comm::deletePlane(int ID){
   		/*while(pthread_mutex_lock( &a_space )!=0);
   		for(int i = 0; i < airspace.size(); i++){
   			stringstream transformID(airspace[i]->getID());
   			int currentID;
   			transformID >> currentID;
   			if(currentID == ID) {
   				cout << "RESPONSE|Time: " << to_string(GLOBAL_CLOCK) << "| Aircraft with ID " << to_string(ID) << " was removed from airspace \n";
   				while(pthread_mutex_lock( &buffstr )!=0);
   				bufferString+= "RESPONSE|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(ID) + " was removed from airspace \n";
   				pthread_mutex_unlock( &buffstr );
   				airspace.erase(airspace.begin()+i);
   				break;
   			}
   		}
   		pthread_mutex_unlock( &a_space );*/
   	}

   	void comm::hitScan(aircraft* hitobject){
   		pthread_mutex_lock( &a_space );
   		for(int i = 0; i < airspace.size(); i++){
   			if(airspace[i]==hitobject){
   				while(pthread_mutex_lock( &buffstr )!=0);
   				bufferString+= "EXIT|Time: " + to_string(GLOBAL_CLOCK) + "| Aircraft with ID " + to_string(airspace[i]->getID()) + " left airspace\n";
   				pthread_mutex_unlock( &buffstr );
   				airspace.erase(airspace.begin()+i);
   			}
   		}
   		pthread_mutex_unlock( &a_space );
   	}



comm::comm()
{
}

comm::~comm()
{
}
