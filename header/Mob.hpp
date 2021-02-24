#ifndef __MOB_HPP__
#define __MOB_HPP__

#include "basic_unit.hpp"
#include <string>
#include <iostream>

class Mob : public basic_unit{
	private:
		std::string mobDescription;
		int healthCap;
	public:
		Mob(std::string _name, int _health, int _attack, std::string mobDescription);
		~Mob();
		void attack(Basic_Unit* target);
		void recover();
		void special(Basic_Unit* target);		
		std::string getMobDescription();
};

#endif //__MOB_HPP__
