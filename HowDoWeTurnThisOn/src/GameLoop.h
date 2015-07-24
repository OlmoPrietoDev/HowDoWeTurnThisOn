/*
 * GameLoop.h
 *
 *  Created on: 22 Jul 2015
 *      Author: guillermo
 */

#ifndef GAMELOOP_H_
#define GAMELOOP_H_

#include "Map.h"

class GameLoop {

private:

	Map *m_map;
	int m_iTurn; // 1 or 2
	bool m_bIsGameEnded;

public:
	GameLoop();

	void Loop();

	~GameLoop();
};

#endif /* GAMELOOP_H_ */
