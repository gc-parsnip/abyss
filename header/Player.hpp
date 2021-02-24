#include "Basic_Unit.hpp"
#include <iostream>
#include <string>

class Player : public Basic_Unit {
    private:
        int floorCleared;
        int healthCap;

    public:     
        Player(int _health, int _attack);
        void increment_attack(int bonusAtt);
        void increment_health(int bonusHp);
        void increment_score();
        void equip_weapon(Weapon* _weapon);
        void loot();
};  