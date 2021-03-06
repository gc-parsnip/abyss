#ifndef __MOB_BUILDER_HPP__
#define __MOB_BUILDER_HPP__

#include <string>
#include <vector>
#include "loot.hpp"
#include "Mob.hpp"

class mob_builder
{
protected:
    virtual std::vector<std::string> DetermineName(int) = 0;
    virtual int DetermineAttack(int) = 0;
    virtual int DetermineHealth(int) = 0;
    virtual weapon* DetermineWeapon(int) = 0;
public:
    virtual Mob* GetMob(int) = 0;
};

#endif
