/*
 * Box.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: guillermo
 */

#include <list>
#include "Box.h"

Box::Box(int _id) {

	m_iId = _id;
	m_iBattalionsContained = 0;
	m_stdListBattalionKeeper = new std::list<Battalion*>;
}

Box::~Box() {

	Battalion *battalion;

	while(!m_stdListBattalionKeeper->empty()) {

		battalion = m_stdListBattalionKeeper->front();
		delete battalion;
		m_stdListBattalionKeeper->pop_front();
	}

	delete m_stdListBattalionKeeper;
}

