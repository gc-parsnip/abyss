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
    int baseHealth = 50;
    int baseAttack = 10;
    int bossEveryFloors = 5;
    Mob* generatedMob = nullptr;
    normal_weapon_builder* weaponBuilder = nullptr;
    std::unordered_map<int, std::string> mobNames = {
	{1, "Slime"},
	{2, "Spider"},
	{3, "Rats"},
	{4, "Skeleton"},
	{5, "Zombie"},
	{6, "Mimic"},
	{7, "Goblin"},
	{8, "Hobgoblin"},
	{9, "A Bowl of Snakes"},
	{10, "Bandits"},
	{11, "Kobold"},
	{12, "A Rock"},
	{13, "Orc"},
	{14, "A Fried Egg"},
	{15, "Troll"},
	{16, "Keyboard Warrior"},
	{17, "Beholder"},
	{18, "A Sharp Rock"},
	{19, "Dragon"},
	{20, "Large Tentacle"}
    };
    std::unordered_map<int, std::string> mobDescriptions = {
	{1, "It's bouncing at you. Menacingly!"},
	{2, "*shoots balls of web at you* *pew* *pew* *pew*"},
	{3, "Rats. Multiple."},
	{4, "Sticks and stones may break your bones but this one has a lot of bones."},
	{5, "Its dead, but also not."},
	{6, "If it looks like a chest, smells like a chest, and bites like a chest. Wait."},
	{7, "An average looking goblin. It brandishes a wooden club."},
	{8, "An elite goblin. It's wearing shiny armour and has a cool sword."},
	{9, "Snakes in a bowl. Yum!"},
	{10, "They want your loot."},
	{11, "Has a pickaxe that can be used for mining ore and breaking skulls."},
	{12, "A rock."},
	{13, "Like a goblin, but bigger and with muscles."},
	{14, "An egg that has been previously fried. It's been left here so long it has gained sentience."},
	{15, "Wields a big club. The quote 'Speak softly and carry a big stick' comes to mind."},
	{16, "Has trained in the art of internet arguments since before you were born."},
	{17, "Its a floating eyeball."},
	{18, "You might have faced similar rocks before. This one is leagues more dangerous."},
	{19, "Flying lizard goes brrrrr. Danger!"},
	{20, "An appendage of some larger, scarier creature that has dug its way here."}
    };
    std::unordered_map<int, Loot*> weaponTable;
protected:
    virtual std::vector<std::string> DetermineName(int);
    virtual int DetermineAttack(int);
    virtual int DetermineHealth(int);
    virtual weapon* DetermineWeapon(int);
public:
    basic_mob_builder();
    ~basic_mob_builder();
    virtual Mob* GetMob(int);
};

#endif
