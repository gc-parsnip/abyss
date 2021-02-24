#ifndef __LOOT_HPP__
#define __LOOT_HPP__

#include <string>

class Loot
{
protected:
    std::string itemDescription;
public:
    Loot(std::string description){
	itemDescription = description;
    }
    std::string GetDescription(){
	return itemDescription;
    }
    virtual int use() = 0;
};

#endif
