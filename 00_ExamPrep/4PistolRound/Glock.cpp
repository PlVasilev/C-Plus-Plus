#include "Glock.h"

Glock::Glock(const int damagePerRound,
	const int clipSize,
	const int remainingAmmo) :Pistol(damagePerRound, clipSize, remainingAmmo) {}

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
	if (_remainingAmmo == 0 && _currClipBullets == 0)
	{
		std::cout << "No ammo left" << std::endl;
		return false;
	}
	if (_currClipBullets == 0)
	{
		_remainingAmmo += _currClipBullets;
		_currClipBullets = 0;
		std::cout << "Reloading..." << std::endl;
		if (_remainingAmmo < _clipSize)
		{
			_currClipBullets = _remainingAmmo;
			_remainingAmmo = 0;
		}else
		{
			_currClipBullets = _clipSize;
			_remainingAmmo -= _clipSize;
		}

		if (_remainingAmmo <= 0 && _currClipBullets <= 0)
		{
			_remainingAmmo = 0;
			_currClipBullets = 0;
			std::cout << "No ammo left" << std::endl;
			return false;
		}
		std::cout << "currClipBullets: " << _currClipBullets << ", remainingAmmo: " << _remainingAmmo << std::endl;
		return false;
	}
	for (int i = 0; i < 3; ++i)
	{
		if (enemyPlayerData.armor == 0)
		{
			enemyPlayerData.health -= _damagePerRound;
			_currClipBullets--;
		}
		else
		{
			if (enemyPlayerData.armor - _damagePerRound * 0.5 < 0)
			{
				int dmg = _damagePerRound;
				dmg -= enemyPlayerData.armor;
				enemyPlayerData.armor = 0;
				enemyPlayerData.health -= dmg;
			}
			else
			{
				enemyPlayerData.health -= _damagePerRound * 0.5;
				enemyPlayerData.armor -= _damagePerRound * 0.5;
			}
			_currClipBullets--;
		}
		std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;
		if (enemyPlayerData.health <= 0)
		{
			return true;
		}
		if (_remainingAmmo == 0 && _currClipBullets == 0)
		{
			std::cout << "No ammo left" << std::endl;
			return false;
		}
		if (_currClipBullets == 0 && i < 2)
		{
			_remainingAmmo += _currClipBullets;
			_currClipBullets = 0;
			std::cout << "Reloading..." << std::endl;
			if (_remainingAmmo < _clipSize)
			{
				_currClipBullets = _remainingAmmo;
				_remainingAmmo = 0;
			}
			else
			{
				_currClipBullets = _clipSize;
				_remainingAmmo -= _clipSize;
			}
			if (_remainingAmmo <= 0 && _currClipBullets <= 0)
			{
				_remainingAmmo = 0;
				_currClipBullets = 0;
				std::cout << "No ammo left" << std::endl;
				return false;
			}
			std::cout << "currClipBullets: " << _currClipBullets << ", remainingAmmo: " << _remainingAmmo << std::endl;
			return false;
		}
	}
	return false;

}
