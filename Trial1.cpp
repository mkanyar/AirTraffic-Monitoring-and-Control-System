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

		char* line = NULL;
		int len = 0;
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

	char* line = NULL;
	int len = 0;
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
		cout << "Welcome to the Momentics IDE" << endl;
		aircraft name("hello",1,2,3,4,5,6);
		cout<<"object created"<<endl;


		pthread_t tid1, tid2;
		tid1 = createSchedFifoThread(displaye_manager_thread, 10, SCHED_RR, false);
		tid2 = createSchedFifoThread(write_file_thread, 10, SCHED_RR, false);

		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
		return 0;
}

































































