#ifndef __FLOOR_BUILDER_HPP__
#define __FLOOR_BUILDER_HPP__

#include "attack_pot.hpp"
#include "combo_pot.hpp"
#include "health_pot.hpp"
#include "Mob.hpp"
#include "floors.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Floor_Builder {
    protected: 
        Floor* _floor;
        std::vector<std::string> scenery;
        Loot* _loot;
        std::string currentScene;

    public:
        virtual void resetFloor() = 0;
        virtual void spawnMobs() = 0;
        virtual void spawnLoot() = 0;
        virtual Floor* createFloor(int index) = 0;
        virtual void setScenery(int index) = 0;
};

#endif