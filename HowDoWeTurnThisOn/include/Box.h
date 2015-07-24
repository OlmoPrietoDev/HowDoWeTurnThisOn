/*
 * Box.h
 *
 *  Created on: 8 Jul 2015
 *      Author: guillermo
 */

#ifndef BOX_H_
#define BOX_H_

#include <list>
#include "Battalion.h"

class Box {

private:

	int m_iId;
	int m_iBattalionsContained;
	std::list<Battalion*> *m_stdListBattalionKeeper;




public:
	Box(int _id);
	~Box();
};

#endif /* BOX_H_ */
