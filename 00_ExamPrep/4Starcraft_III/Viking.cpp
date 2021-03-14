#include "Viking.h"


#include <iostream>
#include <ostream>

Viking::Viking(const AirShipType type,
               const int         health,
               const int         baseDamage,
               const int         shipId):TerranAirShip(type, health, baseDamage, shipId){}


void Viking::dealDamage(
    std::vector<std::unique_ptr<AirShip>> & enemyFleet) {

    if (enemyFleet.back()->getAirShipType() == AirShipType::PHOENIX)
    {
        enemyFleet.back()->takeDamage(this->_damage * 2);
        if (enemyFleet.back()->getCurrHealth() <= 0)
        {
            std::cout << "Viking with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
            enemyFleet.pop_back();
        }
    }
	else
	{
        enemyFleet.back()->takeDamage(this->_damage);
        if (enemyFleet.back()->getCurrHealth() <= 0)
        {
            std::cout << "Viking with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
            enemyFleet.pop_back();
        }
	}
};