#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "Mob.hpp"


class Floor {
    private:
        std::string floor_type;
        std::vector<Mob*> mobs;
        std::string floor_description;
        Loot* floor_loot;

    public:
        Floor(std::string type) {
            floor_type = type; 
        }

        void addMob(Mob* _mob) {
            mobs.push_back(_mob);
        }

        void setDescription(std::string description) {
            floor_description = description;
        }

        void setLoot(Loot* _loot) {
            floor_loot = _loot;
        }

        std::string displayFloorDescription() {
            return floor_description;
        }
        
        Loot* getLoot() {
            return floor_loot;
        }

        void clearMobs() {
            for (unsigned int i = 0; i < mobs.size(); i++) {
                delete mobs.at(i);
                mobs.erase(mobs.begin() + i);
            }
        }
        
        void clearLoot() {
            delete floor_loot;
        }


};

#endif