#include "../header/player.hpp"


Player::Player(std::string _name, int _health, int _attack) : Basic_Unit (_name, _health, _attack) {
    floorCleared = 0;
    healthCap = _health;
}

Player::~Player() {

    delete currentWeapon;

}

void Player::attack(Basic_Unit* target) {
    int attack;
    if (currentWeapon != nullptr) {
        attack = attackValue + currentWeapon->use();
        target->decrease_health(attack);
    } else {
        attack = attackValue;
        target->decrease_health(attack);
    } 
    std::cout << name << " has dealt " << std::to_string(attack) << " damage to " << target->get_name() << ". " 
    << target->get_name() << " has " << std::to_string(target->get_health()) << "/" << std::to_string(target->getHealthCap()) << " health remaining." <<
    std::endl; //need to specify what monster for future reference.
}

void Player::recover() {
    if (health < healthCap) {
        health += healthCap-90;
        if (health > healthCap) {
            health = healthCap;
        }
        std::cout << name << " has recovered " << healthCap-90 << " health. " << std::to_string(health) << "/"
        << std::to_string(healthCap) << std::endl;
    } else {
        std::cout << "Recover failed. " << name << " is full health. " << std::to_string(health) << "/"
        << std::to_string(healthCap) << std::endl;
    }
}

void Player::special(Basic_Unit* target) {
    target->decrease_health(attackValue + 50); //not sure how this damage will be calculated either
    std::cout << name << " casts Firebolt on " << target->get_name() << ". " << name << " deals " << std::to_string(attackValue + 50) << " damage to "
    << target->get_name() << ". " << target->get_name() << " has " << std::to_string(target->get_health()) << "/" << std::to_string(target->getHealthCap()) << " health remaining." <<
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

int Player::get_score() {
    return floorCleared;
}

int Player::inspect_hp(Basic_Unit* target) {
    return target->get_health();
}
