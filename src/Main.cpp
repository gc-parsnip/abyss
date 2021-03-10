#include "../header/player.hpp"
#include "../header/floors.hpp"
#include "../header/director.hpp"
#include "../header/normal_floor_builder.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

bool game(Floor *floor, Player *player);

void move(Player *player, Mob *mob);

void options(Floor *floor, Player *player);

int main()
{
	srand(time(NULL));
	std::string userInput;
	int floorCounter = 0;
	while (true)
	{
		std::cout << "Welcome to the Abyss" << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Please select from the following options." << std::endl;
		std::cout << "1.Delve into the Abyss." << std::endl;
		std::cout << "2.How to play." << std::endl;
		std::cout << "3.Quit." << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cin >> userInput;

		if (userInput == "1") //if user chooses 1
		{
			std::cout << "Please enter your name: ";
			std::cin >> userInput;
			Player player = Player(userInput, 100, 25);
			std::cout << std::endl;
			std::cout << "Hey, you. You're finally awake.\nWe're at our destination.\nThe Abyss invites you in..." << std::endl;
			std::cout << std::endl;

			bool go = true;
			Normal_Floor_Builder nf;
			Director dir(&nf);
			Floor *floor;
			while (go)
			{
				floor = dir.generateFloor(floorCounter%5, &player);
				floorCounter += 1;
				go = game(floor, &player);
				std::cout << std::endl;
				dir.destroyFloor();
			}
		}
		else if (userInput == "2") //if user chooses 2
		{
			std::string text;
			std::ifstream instructions;

			instructions.open("instructions.txt");
			if (!instructions)
			{
				std::cout << "Error opening file.";
				exit(1); // return with error
			}
			while (getline(instructions, text))
			{
				std::cout << text << std::endl;
			}
			instructions.close();
			std::cout << std::endl;
		}
		else if (userInput == "3") //if user chooses 3
		{
			std::cout << "The program has been terminated." << std::endl;
			std::cout << "Press Enter to continue..."; 
			while (std::cin.get()!='\n'); 
			return 0;
		}
		else //other
		{
			std::cout << "Invalid entry, please try again. " << std::endl;
		}
	}
	return 0;
}

bool game(Floor *floor, Player *player)
{
	std::cout << floor->displayFloorDescription() << std::endl;
	std::vector<Mob *> mobPool = floor->getMobs();
	Mob *mob1 = mobPool.at(0);
	std::cout << player->get_name() << " encounters " << mob1->get_name() << "." << std::endl;
	std::cout << mob1->getMobDescription() << std::endl;
	std::cout << std::endl;

	while (player->get_health() > 0 && mob1->get_health() > 0)
	{
		move(player, mob1);
		if (mob1->get_health() <= 0)
		{
			std::cout << mob1->get_name() << " has been slain." << std::endl;
			break;
		}
		else
		{
			mob1->attack(player);
		}
	}
	if (player->get_health() <= 0)
	{
		std::cout << "Game Over." << std::endl;
		std::cout << "You have cleared " << player->get_score() << " floor(s)." << std::endl;
		std::cout << "Press Enter to continue..."; 
		while (std::cin.get()!='\n'); 
		return false;
	}
	else
	{
		player->increment_score();
		options(floor, player);
		std::cout << "You proceed to the next floor." << std::endl;
		std::cout << "Press Enter to continue..."; 
		while (std::cin.get()!='\n'); 
		return true;
	}
}

void move(Player *player, Mob *mob)
{
	std::cout << "Please choose a move." << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Guard" << std::endl;
	std::cout << "3. Recover" << std::endl;
	std::cout << "4. Special" << std::endl;

	std::string userInput;
	std::cin >> userInput;
	std::cin.ignore();
	bool flag = false;

	while (!flag)
	{
		if (userInput == "1")
		{
			player->attack(mob);
			flag = true;
		}
		else if (userInput == "2")
		{
			player->guard("on");
			flag = true;
		}
		else if (userInput == "3")
		{
			player->recover();
			flag = true;
		}
		else if (userInput == "4")
		{
			player->special(mob);
			flag = true;
		}
		else
		{
			std::cout << "Please enter a valid move." << std::endl;
			std::cin >> userInput;
		}
	}
	std::cout << std::endl;
}

void options(Floor *floor, Player *player)
{
	std::string userInput;
	std::cout << "Please make a choice." << std::endl;
	std::cout << "1. Proceed to next floor." << std::endl;
	std::cout << "2. Inspect floor for loot." << std::endl;
	std::cin >> userInput;

	std::cin.ignore();
	bool flag = false;
	bool looted = false;
	while (!flag)
	{
		if (userInput == "1")
		{
			return;
		}
		else if (userInput == "2")
		{
			if (looted != true)
			{
				Loot *temp = floor->getLoot();
				std::cout << "You found: " << temp->GetDescription() << std::endl;
				switch (temp->use())
				{
				case 5:
					std::cout << "The pot has an attack value of 5." << std::endl;
					break;
				case 10:
					std::cout << "The pot has a health value of 10." << std::endl;
					break;
				default:
					std::cout << "The weapon has an attack value of " << std::to_string(temp->use()) << "." << std::endl;
				}

				std::cout << "Would you like to take it?" << std::endl;
				std::cout << "1. Yes." << std::endl;
				std::cout << "2. No." << std::endl;
				std::string userChoice;
				std::cin >> userChoice;
				std::cin.ignore();
				bool use = false;

				while (!use)
				{
					if (userChoice == "1")
					{
						looted = true;
						switch (temp->use())
						{
						case 5:
							player->increment_attack(temp->use());
							break;
						case 10:
							player->increment_health(temp->use());
							break;
						default:
							player->set_weapon(static_cast<weapon*>(temp));
							floor->equipped();
						}
						use = true;
					}
					else if (userChoice == "2")
					{
						return;
					}
					else
					{
						std::cout << "Please enter a valid move." << std::endl;
						std::cin >> userChoice;
					}
				}
				flag = true;
			}
			else
			{
				std::cout << "Please enter a valid choice." << std::endl;
				std::cin >> userInput;
			}
		} else {
			std::cout << "Please enter a valid choice." << std::endl;
			std::cout << "1. Proceed to next floor." << std::endl;
			std::cout << "2. Inspect floor for loot." << std::endl;
			std::cin >> userInput;
		}
	}
}