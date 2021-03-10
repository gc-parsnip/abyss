#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "basic_unit.hpp"
#include "weapon.hpp"
#include <iostream>
#include <string>

class Player : public Basic_Unit {
    private:
        int floorCleared;
    
    public:     
        Player(std::string _name, int _health, int _attack);
        ~Player();
        void attack(Basic_Unit* target);
        void recover();
        void special(Basic_Unit* target);
        void increment_attack(int bonusAtt);
        void increment_health(int bonusHp);
        void increment_score();
        void loot();
        int inspect_hp(Basic_Unit* target);
        int get_score();
};  

#endif
