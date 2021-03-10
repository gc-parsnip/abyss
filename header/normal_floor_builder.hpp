#ifndef __NORMAL_FLOOR_BUILDER_HPP__
#define __NORMAL_FLOOR_BUILDER_HPP__

#include "floor_builder.hpp"
#include <fstream>



//#include "mob_builder.hpp"

class Normal_Floor_Builder : public Floor_Builder {

    public:
        Normal_Floor_Builder() {
            std::ifstream in;
            in.open("./GameText/FloorDescriptions.txt");
            std::string line;
            if (in.is_open()) {;
                while (std::getline(in, line, '~')) {
                    scenery.push_back(line);
                }
            } else {
                std::cout << "Failed to open FloorDescriptions.txt" << std::endl;
            }
            in.close();
        }

        Floor* createFloor(int index) {
            _floor = new Floor("normal");
            currentScene = scenery.at(index);
            _floor->setDescription(currentScene);
            return _floor;
        }

        void resetFloor() {
            _floor->clearMobs();
            _floor->clearLoot();
        }

        void spawnMobs() {
            //wait til adding mobFile before implementing function
        }

        void spawnLoot() {
            int randVal = std::rand()%1;
            if (randVal == 0) {
                 _floor->setLoot(new attack_pot(5, "A glass bottle with a strange pink liquid"));
            } else if (randVal == 1) {
                _floor->setLoot(new health_pot(10, "A glass bottle with a strange red liquid."));
            } else {
                std::cout << "Weapon Case" << std::endl;
            }
        }

        void setScenery(int index) {
            _floor->setDescription(scenery.at(index));
        }
        
};

#endif