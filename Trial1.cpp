#include <iostream>
#include "aircraft.h"
#include <iostream>
#include <fstream>

using namespace std;
void displayer(){
	string line;
	ifstream myfile ("Tracker.txt");
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	      cout << line << '\n';
	    }
	    myfile.close();
	  }

	  else cout << "Unable to open file";
}
int main() {
	cout << "Welcome to the Momentics IDE" << endl;
	aircraft name("hello",1,2,3,4,5,6);
	cout<<"object created"<<endl;
	map<string,int*>mymap;
	name.hit(mymap);
	cout<<mymap["hello"][0]<<endl;
	displayer();
	return 0;
}

































































