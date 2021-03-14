#include "Carrier.h"


#include <iostream>
#include <ostream>

Carrier::Carrier(const AirShipType type,
                 const int         health,
                 const int         damage,
                 const int         maxShield,
                 const int         shieldRegenerateRate,
                 const int         shipId):ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId)
{}



void Carrier::takeDamage(const int damage) {
	ProtossAirShip::takeDamage(damage);
};

void Carrier::dealDamage(
    std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
	if (this->_maxHealth == this->_currHealth)
	{
		for (int i = 0; i < InterceptorDefines::MAX_INTERCEPTORS; ++i)
		{
			enemyFleet.back()->takeDamage(this->_damage);
			if (enemyFleet.back()->getCurrHealth() <= 0)
			{
				std::cout << "Carrier with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
				enemyFleet.pop_back();
				if (enemyFleet.empty()) return;
			}
		}
	}else
	{
		for (int i = 0; i < InterceptorDefines::DAMAGED_STATUS_INTERCEPTORS; ++i)
		{
			enemyFleet.back()->takeDamage(this->_damage);
			if (enemyFleet.back()->getCurrHealth() <= 0)
			{
				std::cout << "Carrier with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;
				enemyFleet.pop_back();
				if (enemyFleet.empty()) return;
			}
		}
	}
};