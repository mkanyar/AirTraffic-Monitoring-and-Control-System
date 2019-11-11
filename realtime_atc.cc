#include <cstdlib>
#include <iostream>
#include "aircraft.h"

int main(int argc, char *argv[]) {
	std::cout << "Welcome to the Momentics IDE" << std::endl;
	aircraft name = new aircraft("hello",0,0,0,0,0,0);
	std::cout<<name.getX()<<std::endl;
	std::cout<<"object created"<<std::endl;
	return EXIT_SUCCESS;
}
