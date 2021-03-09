#ifndef __BASIC_MOB_BUILDER_HPP__
#define __BASIC_MOB_BUILDER_HPP__

#include <string>
#include <unordered_map>
#include "weapon.hpp"
#include "Mob.hpp"
#include "mob_builder.hpp"
#include "normal_weapon_builder.hpp"

class basic_mob_builder : public mob_builder
{
private:
    Mob* generatedMob = nullptr;
    normal_weapon_builder* weaponBuilder = nullptr;
    std::unordered_map<int, std::string> mobNames = {
	{1, "Goblin"},
	{2, "Gnoll"}};
    std::unordered_map<int, std::string> mobDescriptions = {
	{1, "Short and fast, but never particularly aware of its surroundings."},
	{2, "Tall and clumsy, lacking ambition."}};
    std::unordered_map<int, Loot*> weaponTable;
protected:
    virtual std::vector<std::string> DetermineName(int);
    virtual int DetermineAttack(int);
    virtual int DetermineHealth(int);
    virtual weapon* DetermineWeapon(int);
public:
    basic_mob_builder();
    virtual Mob* GetMob(int);
};

#endif
