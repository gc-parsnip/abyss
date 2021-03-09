#include "../header/player.hpp"


Player::Player(std::string _name, int _health, int _attack) : Basic_Unit (_name, _health, _attack) {
    floorCleared = 0;
    healthCap = _health;
}

Player::~Player() {
    
}

void Player::attack(Basic_Unit* target) {
    // if (weapon != nullptr) {
        //implement some weapon modifier damage
    // } else {
    target->decrease_health(attackValue);
    // } not sure how the damage will be calculated yet
    std::cout << name << " has dealt " << std::to_string(attackValue) << " damage to " << target->get_name() << ". " 
    << target->get_name() << " has " << std::to_string(target->get_health()) << "/" << std::to_string(healthCap) << " health remaining." <<
    std::endl; //need to specify what monster for future reference.
}

void Player::recover() {
    if (health < healthCap) {
        health += 10;
        std::cout << name << " has recovered 10 health. " << std::to_string(health) << "/"
        << std::to_string(healthCap) << std::endl;
    } else {
        std::cout << "Recover failed. " << name << " is full health. " << std::to_string(health) << "/"
        << std::to_string(healthCap) << std::endl;
    }
}

void Player::special(Basic_Unit* target) {
    target->decrease_health(attackValue + 50); //not sure how this damage will be calculated either
    std::cout << name << " casts Firebolt on " << target->get_name() << ". " << name << " deals " << std::to_string(attackValue) << " damage to "
    << target->get_name() << ". " << target->get_name() << " has " << std::to_string(target->get_health()) << "/" << std::to_string(healthCap) << " health remaining." <<
    std::endl; //need to specify what monster for future reference.
}

void Player::increment_attack(int bonusAtt) {
    attackValue += bonusAtt;
    std::cout << name << "'s attack has increased by " << std::to_string(bonusAtt) <<
    ". " << name << "'s current attack is " << std::to_string(attackValue) << "." << std::endl;
}

void Player::increment_health(int bonusHp) {
    health += bonusHp;
    healthCap += bonusHp;
    std::cout << name <<"'s health has increased by " << std::to_string(bonusHp) <<
    ". " << name << "'s current health is " << std::to_string(health) << "/" << 
    std::to_string(healthCap) << "." << std::endl;
}

void Player::increment_score() {
    floorCleared++;
}

// void Player::equip_weapon(Weapon* _weapon) {
//     weapon = _weapon;
// }

void Player::loot() {
    //implement floor class to implement this function
    std::cout << "need to implement" << std::endl;
}

int Player::get_score() {
    return floorCleared;
}

int Player::inspect_hp(Basic_Unit* target) {
    return target->get_health();
}
