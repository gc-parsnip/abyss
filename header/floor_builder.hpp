#ifndef __FLOOR_BUILDER_HPP__
#define __FLOOR_BUILDER_HPP__

#include "loot.hpp"
#include "Mob.hpp"
#include "floors.hpp"
#include <iostream>
#include <string>

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
        virtual Floor* generateFloor(int index) = 0;
        virtual void setScenery(int index) = 0;
};

#endif