/*
 * trackfile.h
 *
 *  Created on: 13-Nov-2019
 *      Author: Aaron Liang
 */

#ifndef TRACKFILE_H_
#define TRACKFILE_H_

#include "aircraft.h"

extern "C" void write_file_thread();
extern string bufferString;
/*
The track file is the major data structure used by several processes to store current position, time-stamped previous positions,
velocity and identification for each aircraft in the space.
*/

class trackfile : public aircraft
{

private:
	//current position
	aircraft ac_position;

	//list of all past positions
	vector<aircraft> ac_position_history;

	//.txt file to persist previous positions
	ofstream log_file;

public:
	trackfile();

	trackfile(aircraft ac);

	//set new current position and save old into history data structure AND log.txt
	void newCurrentPosition(int id, int speed_x, int speed_y, int speed_z, int x, int y, int z, int time);

	aircraft getCurrentPosition();
	vector<aircraft> getPreviousPositions();

	void* write_file_thread(void*);

	virtual ~trackfile();
};


#endif /* TRACKFILE_H_ */
