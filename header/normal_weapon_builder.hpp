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
    std::unordered_map<int, std::string> weaponDescriptions = {
	{1, "A small handmade knife."},
	{2, "A large club, similar to that of the goblins."},
	{3, "A rock worn down to form a simple weapon."},
	{4, "A staff of careful, intricate design."},
	{5, "A large stick covered in rats. Live rats."},
	{6, "A prestine dinner set consisting of a fork and knife."},
	{7, "A basic sword."},
	{8, "A tooth taken from some massive creature."},
	{9, "A sentient sword. You do not know this, as it cannot talk."},
	{10, "A hefty tome written in a language you do not understand."},
	{11, "A blade with edges in all directions. Very difficult to hold."},
	{12, "A rock tied to the end of a sturdy rope."},
	{13, "A sword with a hidden compartment that contains a minature version of the same sword."},
	{14, "A comically large foam finger."},
	{15, "A log of wood."},
	{16, "A large axe of intricate design."},
	{17, "A handful of magic sand."},
	{18, "A lance. Difficult to hold without a horse."},
	{19, "A set of two daggers that fit together to make a larger sword."},
	{20, "A sword so unbelievably massive that is a miracle you can even weild it"},
    };
protected:
    virtual int DetermineAttackValue(int floorNumber);
    virtual std::string DetermineDescription(int floorNumber);
public:    
    virtual weapon* GetWeapon(int floorNumber);
};

#endif
