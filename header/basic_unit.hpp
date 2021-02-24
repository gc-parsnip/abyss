#ifndef __BASIC_UNIT_HPP__
#define __BASIC_UNIT_HPP__

#include "Weapon.hpp"
#include <string>
#include <iostream>

class Basic_Unit {
    protected:
        std::string name;
        int health;
        int attackValue;
        bool guarded;
        // Weapon* weapon;

    public:
        Basic_Unit(std::string _name, int _health, int _attack) {
            name = _name;
            health = _health;
            attackValue = _attack;
            //weapon = nullptr;
        }
        virtual ~Basic_Unit() = default;
        virtual void attack(Basic_Unit* target) = 0;
        virtual void recover() = 0;
        virtual void special(Basic_Unit* target) = 0;
        int get_health() {return health;}
        int get_attack() {return attackValue;}
        std::string get_name() {return name;}
        void decrease_health(int damage) {health -= damage;}
        void guard(std::string on_or_off) {
            if (on_or_off == "on") {
                guarded = true;
                std::cout << name << "is guarding for this turn." << std::endl;
            }
            else {
                guarded = false;
                std::cout << name << "'s guard has worn off." << std::endl;
            }
        }
};

#endif
