#ifndef __COMBO_POT_HPP__
#define __COMBO_POT_HPP__

#include "loot.hpp"

class combo_pot : public Loot
{
private:
    Loot* firstPot;
    Loot* secondPot;
public:
    combo_pot(Loot* firstPot, Loot* secondPot, std::string description) : Loot(description) {
	this->firstPot = firstPot;
	this->secondPot = secondPot;
    }

    combo_pot(Loot* firstPot, Loot* secondPot) : Loot("") {
	this->firstPot = firstPot;
	this->secondPot = secondPot;
    }
    
    ~combo_pot() {
	delete firstPot;
	delete secondPot;
    }

    virtual int use() {
	return firstPot->use() + secondPot->use();
    }
};

#endif
