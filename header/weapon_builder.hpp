#ifndef __WEAPON_BUILDER_HPP__
#define __WEAPON_BUILDER_HPP__

#include <string>
#include "loot.hpp"
#include "weapon.hpp"

class weapon_builder
{
protected:
    virtual int DetermineAttackValue(int floorNumber) = 0;
    virtual std::string DetermineDescription(int floorNumber) = 0;
public:
    virtual weapon* GetWeapon(int floorNumber) = 0;
};

#endif
