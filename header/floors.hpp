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

        std::string displayFloorDescription() {
            return floor_description;
        }
        
        void clearMobs() {
            for (unsigned int i = 0; i < mobs.size(); i++) {
                delete mobs.at(i);
                mobs.erase(mobs.begin() + i);
            }
        }


};

#endif