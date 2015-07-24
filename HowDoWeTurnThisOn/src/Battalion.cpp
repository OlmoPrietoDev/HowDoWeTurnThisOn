/*
 * Battalion.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: guillermo
 */

#include <Battalion.h>

Battalion::Battalion(int maxHP, int maxMovement, int damage, int x, int y) {

	MAXHP = m_iHp = maxHP;
	MAXMOVEMENT = m_iMovement = maxMovement;
	m_iDamage = damage;
	m_iXPosition = x;
	m_iYPosition = y;
	m_bIsDead = (m_iHp < 0);

}

int Battalion::doDamage() {

	return m_iDamage;
}

bool Battalion::receiveDamage(int amount) {

	m_iHp -= amount;
	m_bIsDead = (m_iHp < 0);

	return m_bIsDead;
}

void Battalion::heal(int amount) {

	(m_iHp + amount < MAXHP) ? m_iHp += amount : m_iHp = MAXHP;
}

bool Battalion::move(int xPosition, int yPosition) {

	if(std::abs (xPosition - m_iXPosition) + std::abs (yPosition - m_iYPosition)
		<= m_iMovement) {

		m_iXPosition += xPosition;
		m_iYPosition += yPosition;

		return true;
	}

	return false;
}

void Battalion::newTurn() {

	m_iMovement = MAXMOVEMENT;
}

Battalion::~Battalion() {
}

