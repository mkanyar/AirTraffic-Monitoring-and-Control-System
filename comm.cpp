#include "comm.h"
#include "aircraft.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

/*NOTE: I think these attributes are for aircrafts only*/
    //string comm:: getID(){return this->ID;};
    //float comm::getX(){return this->x;}
   	//float comm::getY(){return y;};
   	//float comm::getZ(){return z;};

//   	float comm::getSpeedX(){return speed_x;};
//   	float comm::getSpeedY(){return speed_y;};
//   	float comm::getSpeedZ(){return speed_z;};
//   	float comm::getEntryTime(){return entry_time;};
//   	void comm::changeSpeed(float x,float y,float z)
//   	{
//   	speed_x=x;
//   	speed_y=y;
//   	speed_z=z;
//   	}

   	void receiveMessage(vector <string> tokens){
   		string TaskNumber = tokens[0];
   		stringstream transform(TaskNumber);
   		int T1 = 0;
   		int T2 = 0;
   		int T3 = 0;
   		int T4 = 0;

   		//Four tokens at max.
   		if(tokens.size() == 1){
   			stringstream transform1(tokens[1]);
   			transform1 >> T1;
   		}
   		else if(tokens.size() == 2){
   			stringstream transform1(tokens[1]);
   			stringstream transform2(tokens[2]);
   			transform1 >> T1;
   			transform2 >> T2;
   		}
   		else if(tokens.size() == 3){
   			stringstream transform1(tokens[1]);
   			stringstream transform2(tokens[2]);
   			stringstream transform3(tokens[3]);
   			transform1 >> T1;
   			transform2 >> T2;
   			transform3 >> T3;
   		}
   		else{
   			stringstream transform1(tokens[1]);
   			stringstream transform2(tokens[2]);
   			stringstream transform3(tokens[3]);
   			stringstream transform4(tokens[4]);
   			transform1 >> T1;
   			transform2 >> T2;
   			transform3 >> T3;
   			transform4 >> T4;
   		}

   		int ID = 0;
   		int givenAltitude = 0;


   		int TaskNumberInt = 0;
   		transform >> TaskNumberInt;

   		if(TaskNumberInt == 1){
   			ID = T1;
   			givenAltitude = T2;

//   			for(int i = 0; i < this.; i++){
//   				if(airplanes[i].getID() == ID) {
//   					airplanes[i].setZ(givenAltitude);
//   					}
//   			}
   		}
   		else if(TaskNumberInt == 2){

   		}
   		else if(TaskNumberInt == 3){

   		   		}
   		else if(TaskNumberInt == 4){

   		   		}
   		else if(TaskNumberInt == 5){

   		   		}
   		else if(TaskNumberInt == 6){

   		   		}
   		else if(TaskNumberInt == 7){

   		   		}
   		else if(TaskNumberInt == 8){

   		   		}
   		else{

   		}
   	}

   	//Four tokens at max

   	int ExtractIntegerToken1(vector <string> tokens) {
   	   		   		stringstream transform1(tokens[1]);

   	   		   		int extractedInteger = 0;
   	   		   		transform1 >> extractedInteger;

   	   		   	}

   	int ExtractIntegerToken2(vector <string> tokens) {
   	   	stringstream transform2(tokens[2]);

   	   	int extractedInteger = 0;
   	   	transform2 >> extractedInteger;

   	}

   	int ExtractIntegerToken3(vector <string> tokens) {
   	   	stringstream transform3(tokens[3]);

   	   		int extractedInteger = 0;
   	   		transform3 >> extractedInteger;

   	}

   	int ExtractIntegerToken4(vector <string> tokens) {
   	   		stringstream transform4(tokens[4]);

   	   		int extractedInteger = 0;
   	   		transform4 >> extractedInteger;

   	}



comm::comm(vector <aircraft> CollectedPlanes)
{
	airplanes = CollectedPlanes;

	/*NOTE: I think these attributes are for aircrafts only*/
//	    ID="";
//		x=0;
//		y=0;
//		z=0;
//	    speed_x=0;
//		speed_y=0;
//		speed_z=0;
//		entry_time=0;

}

comm::~comm()
{
}
