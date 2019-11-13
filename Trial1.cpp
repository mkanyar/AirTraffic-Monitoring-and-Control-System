#include <iostream>
#include "aircraft.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <vector>
using namespace std;
extern "C" void displaye_manager();

void write_file(){
	FILE *fp = fopen("Tracker.txt", "a");
	while(feof(fp)){
		fgetc(fp);
	}
	fprintf(fp, "%s %s %s %d %s", "We", "are", "in", 2014,"\n");
	fclose(fp);
}

void displaye_manager(int read_line){
	FILE *fp = fopen("Tracker.txt","r");
	char c;
	string s;
	int line = 0;
	int temp = line;
	   while(!feof(fp))
	   {
	      c = fgetc(fp);
	      s+=c;
	      if(c=='\n'){
	      	 line++;
	      }
	      if(temp!=line)
	      {
	    	  if(temp >= read_line){
	    	  cout<<s;
	    	  }
	    	  temp=line;
	    	  s="";
	      }
	   }
	fclose(fp);
}

void flying_aircrafts(vector<aircraft> aircraft_list){
	for(signed int i =0;i<aircraft_list.size();i++){
		aircraft_list[i].fly();
	}
}

int main() {
	cout << "Welcome to the Momentics IDE" << endl;
	aircraft name("hello",1,2,3,4,5,6);
	cout<<"object created"<<endl;
	map<string,float*>mymap;
	name.hit(mymap);
	//radar.hit(aircraft*,map)
	cout<<mymap["hello"][0]<<endl;
	displaye_manager(0);
	write_file();
	cout<<endl<<"Second Run:" << endl;
	displaye_manager(1);
	cout<<endl<<"Third Run:" << endl;
	displaye_manager(3);
	return 0;
}

































































