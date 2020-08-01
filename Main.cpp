#include <iostream>;
#include <string>;
#include "Unit_Class.h";
#include "Hakespur_Class.h";
#include "Battle_Class.h";
#include <map>;

int main()
{
	
	
	Unit footman;

	footman.increase_stat(3, 5);

	std::cin.get();

	Hakespur hakespurmen1;        
	hakespurmen1.take_dmg(3, -5);

	std::cin.get();

	Battle battle(footman, hakespurmen1);

	const int var = 4;
	int var2 = 2;
	int var3 = var - var;



	std::cin.get();

	return 0;
}