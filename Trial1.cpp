#include <iostream>
#include "aircraft.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <vector>
using namespace std;
extern "C" void display_manager();

void display_manager(int read_line){
	FILE *fp = fopen("Tracker.txt","r");
	char c;
	string s;
	int line = 0;
	int temp=line;
	   while(1)
	   {
	      c = fgetc(fp);
	      s+=c;
	      if(c=='\n'){
	      	 line++;
	      }
	      if(temp!=line)
	      {
	    	  cout<<s;
	    	  temp=line;
	    	  s="";
	      }
	      if( feof(fp) )
	      {
	          break;
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
	aircraft name("ac1",1,2,3,4,5,6,7);
	/*cout << "Welcome to the Momentics IDE" << endl;
	cout<<"object created"<<endl;
	map<string,float*>mymap;
	name.hit(mymap);
	//radar.hit(aircraft*,map)
	cout<<mymap["hello"][0]<<endl;
	display_manager(0);*/
	return 0;
}

































































