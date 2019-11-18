#include <iostream>
#include "aircraft.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <vector>
using namespace std;

void flying_aircrafts(vector<aircraft> aircraft_list){
	for(signed int i =0;i<aircraft_list.size();i++){
		aircraft_list[i].fly();
	}
}

int main() {
	//aircraft name("ac1",1,2,3,4,5,6,7);
	/*cout << "Welcome to the Momentics IDE" << endl;
	cout<<"object created"<<endl;
	map<string,float*>mymap;
	name.hit(mymap);
	//radar.hit(aircraft*,map)
	cout<<mymap["hello"][0]<<endl;
	display_manager(0);*/
	return 0;
}

































































