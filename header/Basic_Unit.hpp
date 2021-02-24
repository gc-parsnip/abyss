#include "Weapon.hpp"

class Basic_Unit {
    protected:
        int health;
        int attack;
        Weapon* weapon;
        int get_health() {return health;}
        int get_attack() {return attack;}

    public:
        BasicUnit(int _health, int _attack) {
            health = _health;
            attack = _attack;
            weapon = nullptr;
        }
        virtual void attack(BasicUnit* target) = 0;
        virtual void guard() = 0;
        virtual void recover() = 0;
        virtual void special(BasicUnit* target) = 0;

};