#ifndef __ATTACK_POT_HPP__
#define __ATTACK_POT_HPP__

#include "loot.hpp"

class attack_pot : public Loot
{
private:
    int value;
public:
    attack_pot(int value, std::string description) : Loot(description), value(value) {}
    attack_pot(int value) : Loot(""), value(value) {}

    virtual int use();
};

#endif
