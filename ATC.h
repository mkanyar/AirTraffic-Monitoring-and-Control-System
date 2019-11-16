/*
 * ATC.h
 */

#ifndef SRC_ATC_H_
#define SRC_ATC_H_
#include "aircraft.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class ATC {
private:
	static const int upperX = 100000;
	static const int lowerX = 0;
	static const int upperY = 100000;
	static const int lowerY = 0;
	static const int upperZ = 25000;
	static const int lowerZ = 0;
	vector<aircraft> aircraftlist;
	bool collision(aircraft a, aircraft b){
		if(abs(a.safe_space[0][2]-b.safe_space[1][2])<=1000 || abs(a.safe_space[1][2] - b.safe_space[0][2])<=1000)
		{
			cout<<a.safe_space[0][2]<< " "<< b.safe_space[1][2]<<endl;
			cout << a.safe_space[1][2]<< " "<< b.safe_space[0][2]<<endl;
			return true;
		}//if a.lowest z is within b.highest z
		//or if a.hightest z is within b.lowest
		else if(abs(a.safe_space[0][1] - b.safe_space[1][1])<=3 || abs(a.safe_space[1][1] - b.safe_space[0][1])<=3)
		{
			//if a.lowest y is within b.highest y
			//or if a.highest y is within b.lowest y
			cout << a.safe_space[0][1] << " "<< b.safe_space[1][1]<<endl;
			cout <<a.safe_space[1][1]<< " "<< b.safe_space[0][1]<<endl;
			return true;
		}


		else if(abs(a.safe_space[0][0] - b.safe_space[1][0])<=0 || abs(a.safe_space[1][0] >= b.safe_space[0][0])<=0)
		{
//			cout << a.safe_space[0][0] << " "<< b.safe_space[1][0]<<endl;
//			cout << a.safe_space[1][0] << " "<< b.safe_space[0][0]<<endl;
			return true;
		}

		else
			return false;
	}
public:
	ATC();
	ATC(vector<aircraft> aircraftlist);
	string Collision_detection();
	virtual ~ATC();
};

#endif /* SRC_ATC_H_ */
