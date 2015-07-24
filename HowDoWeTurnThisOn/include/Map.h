/*
 * Map.h
 *
 *  Created on: 21 Jul 2015
 *      Author: guillermo
 */

#ifndef MAP_H_
#define MAP_H_

#include "Box.h"
#include <vector>
#include <iostream>

static const int MAPSIZE = 225;
static const int BOXESPERFILE = 15;

class Map {

private:

	std::string m_sMapName;
	//TODO in future versions maybe can load map from file

	std::vector<Box*> *m_stdVectorGrid;

public:
	Map();

	void getBox(Box *box, int id);

	~Map();
};

#endif /* MAP_H_ */
