#include "../header/Mob.hpp"

Mob::Mob(std::string _name, int _health, int _attack, std::string mobDescription) : Basic_Unit(_name, _health, _attack)
{
	this->mobDescription = mobDescription;	
	healthCap = _health;
}

Mob::~Mob()
{
    delete currentWeapon;
}

void Mob::attack(Basic_Unit* target)
{
	int attackVal;
	if (target->is_guarded()) {
		attackVal = attackValue - (rand()%51 + 50);
		if (attackVal <= 0) {
			target->decrease_health(0);
			attackVal = 0;	
		} else {
			target->decrease_health(attackVal);
		}
	} else  {
		attackVal = attackValue;
		target->decrease_health(attackVal);
	}
	std::cout << name << " has dealt " << std::to_string(attackVal) << " damage to " << target->get_name() << ". " << target->get_name() << " has " << std::to_string(target->get_health()) << "/" << std::to_string(target->getHealthCap()) << " health remaining." << std::endl; 
}

void Mob::recover()
{
	if(health < healthCap)
	{
		if(healthCap - health >= 10)
		{
		health += 10;
		std::cout << name << " has recovered 10 health. " << std::to_string(health) << "/" << std::to_string(healthCap) << std::endl;
		}
		else
		{
		std::cout << name << " has recovered " << healthCap-health  << " health. " << std::to_string(health) << "/" << std::to_string(healthCap) << std::endl;
		health = healthCap;
		}
		
	}
	else
	{
		std::cout << "Recover failed. " << name << " is full health. " << std::to_string(health) << "/" << std::to_string(healthCap) << std::endl;
	}
}

void Mob::special(Basic_Unit* target)
{
	target->decrease_health(attackValue+50);
	std::cout << name << " casts Special on " << target->get_name() << ". " << name << " deals " << std::to_string(attackValue) << " damage to "
    << target->get_name() << ". " << target->get_name() << " has " << std::to_string(target->get_health()) << "/" << std::to_string(target->getHealthCap()) << " health remaining." <<
    std::endl;
}

std::string Mob::getMobDescription()
{
	return mobDescription;
}
