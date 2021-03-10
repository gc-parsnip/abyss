#ifndef __UNITMOCK_HPP__
#define __UNITMOCK_HPP__

#include "BasicUnit.hpp"
#include "loot.hpp"
#include "weapon.hpp"

class UnitMock : public BasicUnit
{
protected:
    weapon* currentWeapon = nullptr;
public:
    UnitMock(int health, int attack) : BasicUnit(health, attack) {};

    ~UnitMock() {
	delete currentWeapon;
    }

    int GetHealth() {
	return health;
    }

    int GetAttack() {
	return attack;
    }

    int ModHealth(int value) {
	health += value;
    }
    
    int ModAttack(int value) {
	attack += value;
    }

    void SetWeapon(weapon* newWeapon) {
	delete currentWeapon;
	currentWeapon = newWeapon;
    }
};

#endif
