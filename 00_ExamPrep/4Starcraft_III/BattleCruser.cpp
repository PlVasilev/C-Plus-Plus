#include "BattleCruser.h"


#include <iostream>
#include <map>
#include <ostream>

using namespace std;

static map<int, int> bc;

BattleCruser::BattleCruser(const AirShipType type,
	const int         health,
	const int         damage,
	const int         shipId) :TerranAirShip(type, health, damage, shipId) {}


void BattleCruser::dealDamage(
	std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
	int thisShipId = this->getAirShipId();
	if (!bc.count(thisShipId))
	{
		bc[thisShipId] = 1;
	}
	if (bc[thisShipId] != 0 && bc[thisShipId] % 5 == 0)
	{
		enemyFleet.back()->takeDamage(this->_damage * 5);
		if (enemyFleet.back()->getCurrHealth() <= 0)
		{
			std::cout << "BattleCruser with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
			enemyFleet.pop_back();
		}
	}else
	{
		enemyFleet.back()->takeDamage(this->_damage);
		if (enemyFleet.back()->getCurrHealth() <= 0)
		{
			std::cout << "BattleCruser with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
			enemyFleet.pop_back();
		}
	}	
	bc[thisShipId]++;
};