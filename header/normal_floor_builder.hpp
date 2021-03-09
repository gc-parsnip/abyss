#ifndef __NORMAL_FLOOR_BUILDER_HPP__
#define __NORMAL_FLOOR_BUILDER_HPP__

#include "floor_builder.hpp"
#include <fstream>


//#include "mob_builder.hpp"

class Normal_Floor_Builder : public Floor_Builder {

    public:
        Normal_Floor_Builder() {
            scenery = {"hello", "okay", "test"};
            std::ifstream in;
            in.open("../GameText/FloorDescriptions.txt");
            if (in.is_open()) {
                std::string line;
                while (std::getline(in, line, '~')) {
                    scenery.push_back(line);
                }
            } 
            in.close();
        }

        Floor* createFloor(int index) {
            _floor = new Floor("normal");
            currentScene = scenery.at(index);
            _floor->setDescription(currentScene);
            std::cout << scenery.at(index) << std::endl;
            std::cout << scenery.at(1) << std::endl;
        }

        void resetFloor() {
            _floor->clearMobs();
        }

        void spawnMobs() {
            //wait til compile before adding it
        }

        void spawnLoot() {
            
        }

        void setScenery(int index) {
            _floor->setDescription(scenery.at(index));
        }
        
};

#endif