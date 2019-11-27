#include "aircraft.h"
#include "ATC.h"
bool GLOBAL_OVAL=false;
int GLOBAL_CLOCK=0;
string bufferString="";
pthread_mutex_t buffstr = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t a_space = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t e_list = PTHREAD_MUTEX_INITIALIZER;

aircraft::aircraft()
{
	this->entered=false;
	this->old_x=0;
	this->old_y=0;
	this->OVAL=false;
	this->id=0;
	this->x=0;
	this->y=0;
	this->z=0;
	this->speed_x=0;
	this->speed_y=0;
	this->speed_z=0;
	this->time=0;
}

aircraft::aircraft(int id, int speed_x, int speed_y, int speed_z, int x, int y, int z, int time)
{
	this->entered=false;
	this->OVAL=false;
	this->id = id;
	this->speed_x = speed_x;
	this->speed_y = speed_y;
	this->speed_z = speed_z;
	this->x = x;
	this->y = y;
	this->z = z;
	this->time = time;
	this->old_x=0;
	this->old_y=0;
}

int aircraft::getID(){return this->id;}
int aircraft::getX(){return this->x;}
int aircraft::getY(){return this->y;}
int aircraft::getZ(){return this->z;}
int aircraft::getSpeedX(){return this->speed_x;}
int aircraft::getSpeedY(){return this->speed_y;}
int aircraft::getSpeedZ(){return this->speed_z;}
int aircraft::getTime(){return this->time;}

void aircraft::setID(int id){this->id = id;}
void aircraft::setX(int x){this->x = x;}
void aircraft::setY(int y){this->y = y;}
void aircraft::setZ(int z){this->z = z;}
void aircraft::setSpeedX(int speed_x){this->speed_x = speed_x;}
void aircraft::setSpeedY(int speed_y){this->speed_y = speed_y;}
void aircraft::setSpeedZ(int speed_z){this->speed_z = speed_z;}
void aircraft::setTime(int time){this->time = time;}


void aircraft::fly() {
	this->x += this->speed_x;
	this->y += this->speed_y;
	this->z += this->speed_z;
}

bool aircraft::activate(string& bufferString){
	if(GLOBAL_CLOCK>=this->time && !entered){
		entered=true;
		if(this->getID()!=-1){
			while(pthread_mutex_lock( &buffstr )!=0);
			bufferString+="Time: " + to_string(GLOBAL_CLOCK)+"| Aircraft "+to_string(this->id)+" is operating\n";
			pthread_mutex_unlock( &buffstr );
		}

	}
	if(!GLOBAL_CLOCK || !this->OVAL)
	{
		count = 1;
		origin.clear();
	}

	return GLOBAL_CLOCK>=this->time;
}

aircraft::~aircraft(){

}

