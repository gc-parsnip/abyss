#include "../header/Player.hpp"


Player::Player(std::string _name, int _health, int _attack) : Basic_Unit (_name, _health, _attack) {
    floorCleared = 0;
    healthCap = _health;
}

void Player::attack(Basic_Unit* target) {
    // if (weapon != nullptr) {
        //implement some weapon modifier damage
    // } else {
    target->decrease_health(attackValue);
    // } not sure how the damage will be calculated yet
    std::cout << name << " has dealt " << std::to_string(attackValue) << " to the monster." <<
    "Monster has " << std::to_string(target->get_health()) << " health remaining." <<
    std::endl; //need to specify what monster for future reference.
}

void Player::recover() {
    if (health < healthCap) {
        health += 10;
        std::cout << "Player has recovered 10 health. " << std::to_string(health) << "/"
        << std::to_string(healthCap) << std::endl;
    } else {
        std::cout << "Recover failed. You are full health. " << std::to_string(health) << "/"
        << std::to_string(healthCap) << std::endl;
    }
}

void Player::special(Basic_Unit* target) {
    target->decrease_health(attackValue + 50); //not sure how this damage will be calculated either
}

void Player::increment_attack(int bonusAtt) {
    attackValue += bonusAtt;
    std::cout << "Player's attack has increased by " << std::to_string(bonusAtt) <<
    ". Player's current attack is " << std::to_string(attackValue) << "." << std::endl;
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