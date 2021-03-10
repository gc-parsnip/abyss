#include "../header/player.hpp"
#include "../header/floors.hpp"
#include "../header/director.hpp"
#include "../header/normal_floor_builder.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

int main(){
	
	std::string userInput;
	int floorCounter = 0;
	while(true){
		std::cout << "Welcome to the Abyss" << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Please select from the following options." << std::endl;
		std::cout << "1.Delve into the Abyss." << std::endl;
		std::cout << "2.How to play." << std::endl;
		std::cout << "3.Quit." << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cin >> userInput;

		if(userInput == "1") //if user chooses 1
		{
			std::cout << "Plase enter your name: " << std::endl;
			std::cin >> userInput;
			Player player =  Player(userInput, 100, 25);
			std::cout << std::endl;
			std::cout << "Hey, you. You're finally awake.\n We're at our destination.\n The Abyss invites you in..." << std::endl;
			std::cout << std::endl;
			Normal_Floor_Builder nf;
			Director dir(&nf); 
                        Floor* floor = dir.generateFloor(floorCounter%4, &player);
			std::cout << floor->displayFloorDescription() << std::endl;
			std::cout << std::endl;
			floorCounter += 1;
		}
		else if(userInput == "2") //if user chooses 2
		{
			std::string text;
			std::ifstream instructions;
			
			instructions.open("instructions.txt");
			if(!instructions){
				std::cout << "Error opening file.";
				exit(1); // return with error
			}
			while(getline(instructions, text)) {
				std::cout << text << std::endl;
			}
			instructions.close();
			std::cout << std::endl;
		}
		else if(userInput == "3") //if user chooses 3
		{
			std::cout << "The program has been terminated." << std::endl;
			std::cout << "Press any key to continue." << std::endl;
			system("read"); //change to account for all scenarios
			return 0;
		}
		else //other
		{
			std::cout << "Invalid entry, please try again. " << std::endl;
		}
	}
	return 0;
}
