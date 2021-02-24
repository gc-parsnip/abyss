#ifndef __HEALTH_POT_HPP__
#define __HEALTH_POT_HPP__

#include "loot.hpp"

class health_pot : public Loot
{
private:
    int value;
public:
    health_pot(int value, std::string description) : Loot(description), value(value) {}
    health_pot(int value) : Loot(""), value(value) {}

    virtual int use();
};

#endif
