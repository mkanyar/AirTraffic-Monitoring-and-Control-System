#include <iostream>
#include "aircraft.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <ctype.h>
#include <sched.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "ATC.h"
#include "TestCase.h"
#include "trackfile.h"
#include "radar.h"
#include "comm.h"

using namespace std;
extern "C" void displaye_manager_thread();
extern "C" void write_file_thread();
extern "C" void display_manager_c_thread();
bool operator_commanding = false;

void time_stamp(){
	time_t t = time(0);   // get time now
	    tm* now = localtime(&t);
	    cout << (now->tm_year + 1900) << '-'
	         << (now->tm_mon + 1) << '-'
	         <<  now->tm_mday
	         << "\n";
}

//Untested
void* Tokenizer(string message){
	vector <string> tokens;
	int n = message.length();
	char str[n + 1];
	strcpy(str, message.c_str());
	char * token;
	token = strtok (str,",");
	while (token != NULL){
		tokens.push_back(token);
		token = strtok (NULL, ",");
	}

	if(!tokens.empty()){
		//This is a method for 'comm' that will be used when we initialize it.
		comm::receiveMessage(tokens);
	}
}

void* display_manager_c_thread(void* par){
	int n;
	char* token;
	vector<string> string_list;

	while(true){
		while(operator_commanding==true);
		auto start = std::chrono::system_clock::now();
		while(pthread_mutex_lock( &buffstr )!=0);
		n = bufferString.length();
		char tokens[n+1];
		strcpy(tokens, bufferString.c_str());
		pthread_mutex_unlock( &buffstr );
		token = strtok(tokens,"\n");
		//cout<<token<<endl;
		while (token != NULL){
			string_list.push_back(token);
			token = strtok (NULL, "\n");
		}
		for(;line<string_list.size();line++){
			cout<<string_list[line]<<endl;
		}
		string_list.clear();
		auto end = std::chrono::system_clock::now();
		usleep(5000000-(chrono::duration_cast<chrono::microseconds>(end - start).count()));
	}
}

void* Operator_Commands(void* parameter){
	int choice;
	// Add user message to the buffer
		cout<<"-------------------Operator Input Menu-------------------\nOptions:\n";
		cout<<"0. Exit the program"<<endl;
		cout<<"1. Command an aircraft to change Altitude"<<endl;
		cout<<"2. Command an aircraft to change Speed"<<endl;
		cout<<"3. Command an aircraft to change Direction"<<endl;
		cout<<"4. Command an aircraft to Enter a Pattern"<<endl;
		cout<<"5. Command an aircraft to Leave a Pattern"<<endl;
		cout<<"6. Get the status of an aircraft"<<endl;
		cout<<"7. Broadcast to all aircraft to Enter a Pattern"<<endl;
		cout<<"8. Broadcast to all aircraft to Leave a Pattern"<<endl;
		cout<<"9. Broadcast to all aircraft to get their Status"<<endl;
		cin >> choice;

		string message = "";
		string temp = "";

		switch(choice){
		case 0:
			break;
		case 1:
			message = "1,";
			cout <<"Please enter the ID of the aircraft and the altitude to be set in the following form:" << endl;
			cout <<"'id,altitude'" << endl;
			cin>>temp;
			cout<< temp<<endl;
			message+=temp;
			break;
		case 2:
			message = "2,";
			cout <<"Please enter the ID of the aircraft and the velocities to be set of each of the x,y and z coordinates in the following form:" << endl;
			cout <<"'id,x velocity,y velocity,z velocity'" << endl;
			cin>>temp;
			message+=temp;
			break;
		case 3:
			message = "3,";
			cout <<"Please enter the ID of the aircraft and the x and y coordinates of a point in the direction where the aircraft is to be directed to in the following form:" << endl;
			cout <<"'id,x coordinate,ycoordinate'" << endl;
			cin>>temp;
			message+=temp;
			break;
		case 4:
			message = "4,";
			cout <<"Please enter the ID of the aircraft to make it follow an OVAL/HOLDING pattern." << endl;
			cin>>temp;
			message+=temp;
			break;
		case 5:
			message = "5,";
			cout <<"Please enter the ID of the aircraft to make it leave its pattern:" << endl;
			cin>>temp;
			message+=temp;
			break;
		case 6:
			message = "6,";
			cout <<"Please enter the ID of the aircraft to receive its status:" << endl;
			cin>>temp;
			message+=temp;
			break;
		case 7:
			message = "7,";
			cout <<"All aircrafts will be ordered to enter OVAL/HOLDING state." << endl;
			cin>>temp;
			message+=temp;
			break;
		case 8:
			message = "8,";
			cout <<"All the aircrafts will leave their pattern." << endl;

			break;
		case 9:
			message = "9,";
			cout <<"The following are the statuses of all the aircrafts:" << endl;
			break;
		default:
			cout<<"Invalid command, please try again.";


		//comm' receive message Tokenizer(message);
	}
		Tokenizer(message);
}

void* write_file_thread(void* mys){
	int i = 5;
	char* s;
	while(i>0){
	//while(pthread_mutex_lock( &mutex1 )!=0);
	//cout << global_clock<<" Got lock"<<endl;
	s= {"New string\n"};
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
	//GLOBAL_CLOCK++;

	//pthread_mutex_unlock( &mutex1 );
	sleep(4);
	}
}


//void display_manager_c(){
//	FILE* fp = fopen("Tracker.txt", "r");
//	if (fp == NULL)
//	    exit(EXIT_FAILURE);
//	char string[100];
//	while(fgets(string, 100, fp)) {
//	    cout<<string;
//	}
//	fclose(fp);
//}

void* flying_aircrafts(void* arg){
	while(true){
	//cout<<GLOBAL_CLOCK<<endl;
	GLOBAL_CLOCK++;
//	for(unsigned int i =0;i<GLOBAL_AIRCRAFT_LIST.size();i++){
//		if(GLOBAL_AIRCRAFT_LIST[i]->activate(bufferString)){
//			entered_list.push_back(GLOBAL_AIRCRAFT_LIST[i]);
//		}
//	}
	radar::populateEntered();
	for(unsigned int i =0;i<entered_list.size();i++){
		if(!entered_list[i]->OVAL && !GLOBAL_OVAL)
		{
			//cout<<"entering normal fly mode"<<endl;
			entered_list[i]->fly();
		}
		else if(entered_list[i]->activate(bufferString) && (entered_list[i]->OVAL||GLOBAL_OVAL))
		{
			//cout<<"entring oval fly mode"<<endl;
			entered_list[i]->oval();
		}
	}
	sleep(1);
	}


	//}
}



template<typename T>
pthread_t createSchedFifoThread(void* (*pThreadFunc)(void*), int priority, int schedpolicy, T parameter,bool b_detached = false)
{
    pthread_t tid;
    pthread_attr_t attr;
    struct sched_param  param;
    pthread_attr_init(&attr);
    param.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &param);
    pthread_attr_setschedpolicy(&attr, schedpolicy);

    if(b_detached)
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&tid, &attr, pThreadFunc, (void*)&parameter);
    pthread_attr_destroy(&attr);

    return tid;
}

void* console_in(void* arg){
	string choice;
	pthread_t tid1;
	while(true){
		cin>>choice;
		operator_commanding=true;
		tid1 = createSchedFifoThread(Operator_Commands, 98, SCHED_FIFO , NULL,false);
		//Operator_Commands(NULL);
		pthread_join(tid1,NULL);
		operator_commanding=false;
	}
}

int main() {
		GLOBAL_CLOCK=0;
		int len = sizeof(TestCase::airplane_schedule)/sizeof(TestCase::airplane_schedule[0]);
		for(int i =0;i<len;i+=8){
			int id = TestCase::airplane_schedule[i];
			int speed_x = TestCase::airplane_schedule[i+1];
			int speed_y = TestCase::airplane_schedule[i+2];
			int speed_z = TestCase::airplane_schedule[i+3];
			int x = TestCase::airplane_schedule[i+4];
			int y = TestCase::airplane_schedule[i+5];
			int z = TestCase::airplane_schedule[i+6];
			int time = TestCase::airplane_schedule[i+7];
			GLOBAL_AIRCRAFT_LIST.push_back(new aircraft(id,speed_x,speed_y,speed_z,x,y,z,time));
		}
		cout << "Welcome to the ATC System" << endl;
		radar rd();
		comm COMM();
		ATC atc(airspace);
		//pthread_t tid1;
		pthread_t tid1, tid2,tid3,tid4,tid5,tid6;
		tid1 = createSchedFifoThread(flying_aircrafts, 99, SCHED_FIFO , airspace,false);
		tid2 = createSchedFifoThread(display_manager_c_thread, 50, SCHED_RR  , NULL,false);
		tid3 = createSchedFifoThread(atc.Collision_detection,98,SCHED_RR,NULL,false);
		tid4 = createSchedFifoThread(radar::populateAirspace,98,SCHED_RR,NULL,false);
		tid5 = createSchedFifoThread(radar::populateBuffer,50,SCHED_RR,NULL,false);
		tid6 = createSchedFifoThread(trackfile::write_file_thread,50,SCHED_RR,NULL,false);
		console_in(NULL);
		pthread_join(tid3,NULL);
		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
		pthread_join(tid4,NULL);
		pthread_join(tid5,NULL);
		pthread_join(tid6,NULL);
//		auto start = std::chrono::system_clock::now();
//		cout << atc.Collision_detection()<<endl;
//		auto end = std::chrono::system_clock::now();
//				auto elapsed = end - start;
//				cout << "Elapsed time in nanoseconds : "
//						<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
//						<< " ns" << endl;
//
//		start = std::chrono::system_clock::now();
//
//		flying_aircrafts(airspace);
//
//		end = std::chrono::system_clock::now();
//		elapsed = end - start;
//		cout << "Elapsed time in nanoseconds : "
//				<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
//				<< " ns" << endl;
//		//cout<<airspace[0].getID()<<endl;
//		cout<<airspace[0].getX()<<endl;
//		for(aircraft ac:airspace){
//			ac.get_status();
//		}
		return 0;
}





