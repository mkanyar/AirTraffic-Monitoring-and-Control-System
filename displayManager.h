#ifndef DISPLAYMANAGER_H_
#define DISPLAYMANAGER_H_

class displayManager
{
public:
	displayManager();
	virtual ~displayManager();
	
	//scans airspace for all its aircrafts in the following form L=size, Hit(1), Hit(2), ..., Hit(size) where Hit(i) = (ID,(x,y,z))
	// if no transponder, ID field is set as unknown
	void displayAirspaceStatus();
	//Operator commands:
	//1. change altitude
	//2. increase/decrease speed
	//3. change direction horizontally
	//4. enter or leave holding pattern
	//5. report velocity & position
	void displayOperatorResponse(int ID, int operatorCmd);
	
	//display all UNKNOWN contents in airspace
	void displayBackgroundSearch();
	//NOTE: there is also mention of electronic communications to display but not sure if applicable
};

#endif /*DISPLAYMANAGER_H_*/
