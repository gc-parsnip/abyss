#include "./header/Player.hpp"


Player::Player(int _health, int _attack) : Basic_Unit (_health, _attack) {
    floorCleared = 0;
    healthCap = 100;
}

void Player::attack(BasicUnit* target) {
    if (weapon != nullptr) {
        //implement some weapon modifier damage
    } else {
        target->health -= attack;
    } //not sure how the damage will be calculated yet
    std::cout << name << " has dealt " << to_string(attack) << " to the monster." <<
    "Monster has " << to_string(target->health) << " health remaining." <<
    std::endl; //need to specify what monster for future reference.
}

void Player::recover() {
    if (health < healthCap) {
        health += 10;
        std::cout << "Player has recovered 10 health. " << to_string(health) << "/"
        << to_string(healthCap) << std::endl;
    } else {
        std::cout << "Recover failed. You are full health. " << to_string(health) << "/"
        << to_string(healthCap) << std::endl;
    }
}

void Player::special(BasicUnit* target) {
    target->health -= attack * 1.5; //not sure how this damage will be calculated either
}

void Player::increment_attack(int bonusAtt) {
    attack += bonusAtt;
    std::cout << "Player's attack has increased by " << to_string(bonusAtt) <<
    ". Player's current attack is " << to_string(attack) << "." << std::endl;
}

void Player::increment_health(int bonusHp) {
    health += bonusHp;
    healthCap += bonusHp;
    std::cout << name <<"'s health has increased by " << to_string(bonusHp) <<
    ". " << name << "'s current health is " << to_string(health) << "/" << 
    to_string(healthCap) << "." << std::endl;
}

void Player::increment_score() {
    floorCleared++;
}

void Player::equip_weapon(Weapon* _weapon) {
    weapon = _weapon;
}

void Player::loot() {
    //implement floor class to implement this function
}