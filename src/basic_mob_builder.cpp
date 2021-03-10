#include "../header/basic_mob_builder.hpp"
#include "../header/normal_weapon_builder.hpp"
#include "../header/basic_unit.hpp"
#include "../header/Mob.hpp"
#include "../header/loot.hpp"
#include "../header/weapon.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

basic_mob_builder::basic_mob_builder(){
    weaponBuilder = new normal_weapon_builder();
}

std::vector<std::string> basic_mob_builder::DetermineName(int floorNumber){
    int searchRange = floorNumber;
    if(floorNumber > mobNames.size()) searchRange = mobNames.size();
    int RandValue = rand() % (searchRange) + 1;
    std::vector<std::string> nameAndDescription;
    nameAndDescription.push_back(mobNames.find(RandValue)->second);
    nameAndDescription.push_back(mobDescriptions.find(RandValue)->second);
    return nameAndDescription;
}

int basic_mob_builder::DetermineAttack(int floorNumber){
    int RandAttack = 10 + rand() % floorNumber + 1;
    return RandAttack;
}

int basic_mob_builder::DetermineHealth(int floorNumber){
    //int RandHealth = 50 + rand() % (floorNumber + 5) + 1;
    //return RandHealth;
    return 1;
}

weapon* basic_mob_builder::DetermineWeapon(int floorNumber){
    weapon* generatedWeapon = weaponBuilder->GetWeapon(floorNumber);
    return generatedWeapon;
}

Mob* basic_mob_builder::GetMob(int floorNumber){
    std::vector<std::string> nameDescription = DetermineName(floorNumber);
    std::string mobName = nameDescription.at(0);
    std::string mobDescription = nameDescription.at(1);
    int mobHealth = DetermineHealth(floorNumber);
    int mobAttack = DetermineAttack(floorNumber);
    weapon* mobWeapon = DetermineWeapon(floorNumber);

    Mob* generatedMob = new Mob(mobName, mobHealth, mobAttack, mobDescription);
    generatedMob->set_weapon(mobWeapon);
    return generatedMob;
} 
