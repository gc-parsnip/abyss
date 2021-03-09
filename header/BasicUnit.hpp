#ifndef __BASICUNIT_HPP__
#define __BASICUNIT_HPP__

class BasicUnit
{
protected:
    int health;
    int attack;
    Loot* weapon;
public:
    BasicUnit(int health, int attack){
	this->health = health;
	this->attack = attack;
    }

    void SetWeapon(Loot* newWeapon){
	this->weapon = newWeapon;
    }
};

#endif
