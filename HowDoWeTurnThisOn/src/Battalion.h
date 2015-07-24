/*
 * Battalion.h
 *
 *  Created on: 8 Jul 2015
 *      Author: guillermo
 */

#ifndef BATTALION_H_
#define BATTALION_H_

#include <cmath>

// TODO Right place?

class Battalion {

private:

	// Max battalion's hp = MAXHP * MAXUNITS

	int MAXHP; // Maximum hp by unit
// TODO not in this version	int MAXUNITS; // Maximum units by battalion
	int MAXMOVEMENT; // Maximum movement points each turn
	// TODO Right place?
	// TODO more attributes -> +speed +memory think about it

	int m_iHp;
	int m_iDamage;
	int m_iMovement;

	int m_iXPosition;
	int m_iYPosition;

	bool m_bIsDead;
	// TODO necessary? Maybe dead unite = delete unit
	// there is no wizards in this game!

public:

	/*
	 * Description: Constructor. Need hp, movement, damage and initial position
	 * Complexity: O(1)
	 */
	Battalion(int maxHP, int maxMovement, int damage, int x, int y);

	/*
	 * Description: Return damage.
	 * Complexity: O(1)
	 */
	int doDamage();

	/*
	 * Description: hp - amount. Return true if the unit is dead.
	 * Just positive integers, this method is not available for
	 * healing the unit.
	 * Complexity: O(1)
	 */
	bool receiveDamage(int amount);

	/*
	 * Description: hp + amount. At the moment two different
	 * methods, probably not necessary TODO
	 * Complexity: O(1)
	 */
	void heal(int amount);

	/*
	 * Description: Move the battalion to the new x,y positions.
	 * Return false if the movement points are not enough.
	 * Don't care about map limits.
	 * Complexity: O(1)
	 */
	bool move(int xPosition, int yPosition);

	/*
	 * Description: Restore the maximum movement points
	 * Complexity: O(1)
	 */
	void newTurn();

	~Battalion();
};

#endif /* BATTALION_H_ */
