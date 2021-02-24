#ifndef __MOB_HPP__
#define __MOB_HPP__

#include "basic_unit.hpp"
#include <string>
#include <iostream>

class Mob : public Basic_unit{
	private:
		std::string mobDescription;
	public:
		Mob(std::string _name, int _health, int _attack, std::string mobDescription);
		~Mob();
		void attack(Basic_Unit* target);
		void recover();
		void special(Basic_Unit* target);		
		std::string Mob::getMobDescription();
};

#endif __MOB_HPP__
