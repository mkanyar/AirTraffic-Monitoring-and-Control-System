#ifndef COMM_H_
#define COMM_H_
#include <iostream>
#include <strings.h>
#include <vector>
#include <stdio.h>
#include <sstream>
#include "ATC.h"
#include "radar.h"
#include "aircraft.h"

using namespace std;
class comm
{protected:

    vector <aircraft> airplanes;

public:
	comm();
   ~comm();
  comm(vector<aircraft>);

    string getID();

    void receiveMessage(vector <string> tokens);

    void requester(string id, int x, int y, int z);

    void deletePlane(int ID);

    void hitScan(vector <aircraft> hitlist);



	//reporting aircraft leaving airspace (sporadic)
};

#endif /*COMM_H_*/
