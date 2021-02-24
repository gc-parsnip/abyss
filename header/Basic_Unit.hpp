#include "Weapon.hpp"
#include <string>
#include <iostream>

class Basic_Unit {
    protected:
        std::string name;
        int health;
        int attack;
        bool guarded;
        Weapon* weapon;
        void guard;

    public:
        BasicUnit(int _health, int _attack) {
            health = _health;
            attack = _attack;
            weapon = nullptr;
        }
        virtual void attack(BasicUnit* target) = 0;
        virtual void recover() = 0;
        virtual void special(BasicUnit* target) = 0;
        int get_health() {return health;}
        int get_attack() {return attack;}
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