#ifndef __DIRECTOR_HPP__
#define __DIRECTOR_HPP__

#include "floor_builder.hpp"
#include "floors.hpp"
#include "player.hpp"
#include <string>

//Director class can only have 1 floor at a time
class Director { 
    private:
        Floor_Builder* builder;
        Player* player; 
        Floor* new_floor;

    public:
        Director(Floor_Builder* _builder) {
            builder = _builder;
        }
        void changeBuilder(Floor_Builder* _builder) {
            builder = _builder;
        }
        Floor* generateFloor(int index) {
            new_floor = builder->createFloor(index);
            builder->spawnLoot();
            builder->spawnMobs();
            return new_floor;
        }
        
        void destroyFloor() {
            builder->resetFloor(); //clearMobs and clearLoot
            delete new_floor;
        }

};

#endif