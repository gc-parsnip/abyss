//#include "floor_bulder.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

int main(){
	//floorbuilder fb = new floorbuilder();
	std::string userInput;

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
			std::cout << "1 selected" << std::endl;
			//create floorbuilder to start game
		}
		else if(userInput == "2") //if user chooses 2
		{
			std::string text;
			std::ifstream instructions;
			
			instructions.open("instructions.txt");
			if(!instructions){
				std::cout << "Error opening file.";
				exit(1);
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
		else
		{
			std::cout << "Invalid entry, please try again. " << std::endl;
		}
	}
	return 0;
}
