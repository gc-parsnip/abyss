#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include "loot.hpp"
#include <string>

class weapon: public Loot
{
private:
    int value;
    std::string weaponDescription;
public:
    weapon(int value, std::string description) : Loot(description) {
	this->value = value;
	weaponDescription = description;
    }

    virtual int use() {
	return value;
    }

    std::string GetDescription() {
	return weaponDescription;
    }

};

#endif
