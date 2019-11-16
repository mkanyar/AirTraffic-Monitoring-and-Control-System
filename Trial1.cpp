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
using namespace std;
extern "C" void displaye_manager_thread();
extern "C" void write_file_thread();
extern "C" void display_manager_c();


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int global_clock = 0;

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
		receiveMessage(tokens);
	}
}

void* Operator_Commands(void* parameter){
	int choice;
	bool flag = true;
	while(flag){
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
			flag=false;
			break;
		case 1:
			message = "1,";
			cout <<"Please enter the ID of the aircraft and the altitude to be set in the following form:" << endl;
			cout <<"'id,altitude'" << endl;
			cin>>temp;
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
			cout <<"Please enter the ID of the aircraft followed by the type of pattern you would like to put it into in one of the following two forms:" << endl;
			cout <<"'id,holding' or 'id,oval'" << endl;
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
			cout <<"Please enter the type of pattern which you would like all the aircrafts to enter in one of the following two forms:" << endl;
			cout <<"'holding' or 'oval'" << endl;
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
		}

		Tokenizer(message);
	}
}

void* write_file_thread(void* mys){
	int i = 5;
	char* s;
	while(i>0){
	while(pthread_mutex_lock( &mutex1 )!=0);
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
	global_clock++;
	cout << global_clock<<" Finish writing."<<endl;
	pthread_mutex_unlock( &mutex1 );
	sleep(4);
	}
}

void* displaye_manager_thread(void* rl){
	int read_line = 0;
	int actual_line=0;
	int i =5;
	while(i>0){

	//Mutex lock
	while(pthread_mutex_lock( &mutex1 )!=0);
	cout << global_clock<< " Got clock"<<endl;
	cout << global_clock<<" start reading"<<endl;
	FILE* fp = fopen("Tracker.txt", "r");
		if (fp == NULL)
		    exit(EXIT_FAILURE);
		char string[100];
		while(fgets(string, 100, fp)) {
			if(read_line<=actual_line){
				cout<<string;
				read_line++;
			}
			actual_line++;

		}
		fclose(fp);
	i--;
	global_clock++;
	cout << global_clock<<" finish reading line number"<<read_line<<endl;
	pthread_mutex_unlock(&mutex1);
	actual_line=0;
	sleep(5);
	}
	return(0);
}

void display_manager_c(){
	FILE* fp = fopen("Tracker.txt", "r");
	if (fp == NULL)
	    exit(EXIT_FAILURE);
	char string[100];
	while(fgets(string, 100, fp)) {
	    cout<<string;
	}
	fclose(fp);
}

void flying_aircrafts(vector<aircraft> aircraft_list){
	for(signed int i =0;i<aircraft_list.size();i++){
		aircraft_list[i].fly();
	}
}


pthread_t createSchedFifoThread(void* (*pThreadFunc)(void*), int priority, int schedpolicy, bool b_detached = false)
{
    pthread_t tid;
    pthread_attr_t attr;
    struct sched_param  param;
    pthread_attr_init(&attr);
    param.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &param);
    pthread_attr_setschedpolicy(&attr, schedpolicy);

    if(b_detached)
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); //分离模式，无需的等待（pthread_join）之后才释放占用资源，而是返回后自动释放占用的资源

    pthread_create(&tid, &attr, pThreadFunc, NULL);
    pthread_attr_destroy(&attr);

    return tid;
}

int main() {
		int read_line=-1;
		cout << "Welcome to the ATC System" << endl;

//		pthread_t tid1, tid2;
//		tid1 = createSchedFifoThread(displaye_manager_thread, 10, SCHED_RR, false);
//		tid2 = createSchedFifoThread(write_file_thread, 10, SCHED_RR, false);
//
//		pthread_join(tid1,NULL);
//		pthread_join(tid2,NULL);
		aircraft a("1",1,1,1,9,11,1005,0);
		aircraft b("2",1,1,1,9,11,1005,0);
		aircraft c("3",1,1,1,400,200,-15000,0);
		vector<aircraft> airlist;
		airlist.push_back(a);
		airlist.push_back(b);
		airlist.push_back(c);
		ATC atc(airlist);
		cout << atc.Collision_detection()<<endl;
		return 0;
}

































































