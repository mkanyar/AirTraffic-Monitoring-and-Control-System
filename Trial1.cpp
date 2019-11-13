#include <iostream>
#include "aircraft.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <pthread>
using namespace std;
extern "C" void displayer();

void displayer(){
	FILE *fp = fopen("Tracker.txt","r");
	char c;
	string s;
	int line = -1;
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

































































