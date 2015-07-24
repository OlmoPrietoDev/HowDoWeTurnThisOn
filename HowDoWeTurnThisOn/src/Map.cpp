/*
 * Map.cpp
 *
 *  Created on: 21 Jul 2015
 *      Author: guillermo
 */

#include "Map.h"

Map::Map() {

	m_stdVectorGrid = new std::vector<Box*>;

	for (int i = 0; i < MAPSIZE; i++) {

		m_stdVectorGrid->push_back(new Box(i));
	}
}

void Map::getBox(Box* box, int id) {

	box = (*m_stdVectorGrid)[id];
}

Map::~Map() {

	while (!m_stdVectorGrid->empty()) {

		Box *box;

		box = m_stdVectorGrid->back();
		delete box;
		m_stdVectorGrid->pop_back();
	}

	delete m_stdVectorGrid;
}

