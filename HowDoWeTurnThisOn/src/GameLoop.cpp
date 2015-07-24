/*
 * GameLoop.cpp
 *
 *  Created on: 22 Jul 2015
 *      Author: guillermo
 */

#include "GameLoop.h"

GameLoop::GameLoop() {

	m_map = new Map();
	m_iTurn = 1;
	m_bIsGameEnded = false;
}

void GameLoop::Loop() {

	int xInGrid, yInGrid;
	float xInCoord, yInCoord;

	while (!m_bIsGameEnded) {

		//TODO Detect mouse, block?


	}
}

GameLoop::~GameLoop() {
	// TODO Auto-generated destructor stub
}

