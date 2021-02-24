#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include "loot.hpp"
#include <string>

class weapon: public Loot
{
private:
    int value;
public:
    weapon(int value, std::string description) : Loot(description) {
	this->value = value;
    }

    virtual int use() {
	return value;
    }
};

#endif
