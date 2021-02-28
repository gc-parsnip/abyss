//#include "floor_bulder.hpp"
#include <string>
#include <iostream>
#include <cstdio>

int main(){
	//floorbuilder fb = new floorbuilder();
	int userInput;

	while(true){
		std::cout << "Welcome to the Abyss" << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "Please select from the following options." << std::endl;
		std::cout << "1.Delve into the Abyss." << std::endl;
		std::cout << "2.How to play." << std::endl;
		std::cout << "3.Quit." << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cin >> userInput;

		if(userInput == 1)
		{
			std::cout << "1 selected" << std::endl;
		}
		else if(userInput == 2)
		{
			std::cout <<"2 selected" << std::endl;
		}
		else if(userInput == 3)
		{
			std::cout << "The program has been terminated." << std::endl;
			std::cout << "Press any key to continue." << std::endl;
			char a_char;
			a_char = getchar();
			std::cout << a_char;
			return 0;
		}
		else
		{
			std::cout << "Invalid entry, please try again. " << std::endl;
		}
	}
	return 0;
}
