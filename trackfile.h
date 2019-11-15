/*
 * trackfile.h
 *
 *  Created on: 13-Nov-2019
 *      Author: Aaron Liang
 */

#ifndef TRACKFILE_H_
#define TRACKFILE_H_

#include "aircraft.h"

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
	void newCurrentPosition(string id, float speed_x, float speed_y, float speed_z, float x, float y, float z, float time);

	aircraft getCurrentPosition();
	vector<aircraft> getPreviousPositions();

	virtual ~trackfile();
};


#endif /* TRACKFILE_H_ */
