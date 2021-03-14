#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type,
	const int         health,
	const int         damage,
	const int         maxShield,
	const int         shieldRegenerateRate,
	const int         shipId) :AirShip(type, health, damage, shipId),
	_maxShield(maxShield),
	_currShield(maxShield),
	_shieldRegenerateRate(shieldRegenerateRate) {}



void ProtossAirShip::takeDamage(const int damage)
{
	int dmg = damage;
	if (_currShield == 0)
	{
		_currHealth -= dmg;
		return;
	}

	_currShield -= dmg;
	if (_currShield < 0)
	{
		dmg = _currShield * -1;
		_currShield = 0;
	}
	else dmg = 0;

	_currHealth -= dmg;
};

void ProtossAirShip::finishTurn() {
	_currShield += _shieldRegenerateRate;
	if (_currShield > _maxShield) _currShield = _maxShield;
};