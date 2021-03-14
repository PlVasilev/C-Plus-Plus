#include "TerranAirShip.h"

TerranAirShip::TerranAirShip(
    const AirShipType type,
    const int         maxHealth,
    const int         damage,
    const int         shipId):AirShip(type, maxHealth, damage, shipId)
{
	
}



void TerranAirShip::takeDamage(const int damage) 
{
    _currHealth -= damage;
};

void TerranAirShip::finishTurn() {
};