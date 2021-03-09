#include "../header/normal_weapon_builder.hpp"

#include <string>
#include <stdlib.h>
#include "../header/weapon.hpp"

int normal_weapon_builder::DetermineAttackValue(int floorNumber){
    int RandAttack = rand() % floorNumber + 1;
    return (RandAttack/2);
}

std::string normal_weapon_builder::DetermineDescription(int floorNumber){
    int RandValue = rand() % floorNumber + 1;
    return weaponDescriptions.find(RandValue)->second;
}

weapon* normal_weapon_builder::GetWeapon(int floorNumber){
    int weaponValue = DetermineAttackValue(floorNumber);
    std::string weaponDescription = DetermineDescription(floorNumber);
    weapon* newWeapon = new weapon(weaponValue, weaponDescription);
    return newWeapon;
}
