#ifndef __NORMAL_WEAPON_BUILDER_HPP__
#define __NORMAL_WEAPON_BUILDER_HPP__

#include <string>
#include <unordered_map>
#include "weapon_builder.hpp"
#include "loot.hpp"
#include "weapon.hpp"

class normal_weapon_builder : public weapon_builder
{
private:
    weapon* generatedMob = nullptr;
    std::unordered_map<int, std::string> weaponDescriptions = {{1, "A small handmade knife."}};
protected:
    virtual int DetermineAttackValue(int floorNumber);
    virtual std::string DetermineDescription(int floorNumber);
public:    
    virtual weapon* GetWeapon(int floorNumber);
};

#endif
