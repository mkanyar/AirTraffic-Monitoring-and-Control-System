#ifndef COMM_H_
#define COMM_H_
#include <iostream>
#include <strings.h>
#include <vector>
#include "aircraft.h"
#include <stdio.h>
#include <sstream>
#include "ATC.h"
#include "radar.h"

using namespace std;
class comm
{private:


public:
  comm();
   ~comm();

    static void receiveMessage(vector <string> tokens);

    void deletePlane(int ID);

    static void hitScan(aircraft* hitobject);

};

#endif /*COMM_H_*/