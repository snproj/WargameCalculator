#include <iostream>;
#include <string>;
#include "Unit_Class.h"
#include "Battle_Class.h"
#include "Terrain_Class.h"

/* ALREADY DEFINED IN Unit_Class.h1
2
enum Array_Elems
{
	NOFSOL = 0,
	MORALE = 1,
	FRPOWR = 2
};
*/

Battle::Battle(Unit& unit1, Unit& unit2)
{

	terrain1 = 0;
	terrain2 = 0;
	type1 = 0;
	type2 = 0;
	slope1 = 0;
	slope2 = 0;
	name1 = unit1.give_name();
	name2 = unit2.give_name();
	for (int i = 0; i < 3; i++)
	{
		array1[i] = 0;
		array2[i] = 0;
	}
	ranged1 = 0;
	ranged2 = 0;
	active_ranged1 = 0;
	active_ranged2 = 0;
	init_flag = 0;

	std::cout << "============ BATTLE BETWEEN " << name1 << " AND " << name2 << " HAS STARTED ============" << std::endl;

	battle_routine(unit1, unit2, init_flag);
}

void Battle::set_init_flag()
{
	init_flag = 1;

	std::cin.get();
	std::cout << "*****INIT FLAG SET*****" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "INIT_FLAG SET TO " << init_flag << std::endl;
}

void Battle::battle_routine(Unit& unit1, Unit& unit2, bool init_flag)
{
	if (init_flag == 0)
	{
		get_stuff(unit1, unit2);
	}
	else if (init_flag == 1)
	{
		std::cout << "Is the battle between " << name1 << " and " << name2 << " still going on?" << std::endl;
		std::cout << "YES: 1, NO: 0" << std::endl;

		int cont;
		std::cin >> cont;

		if (cont == 0)
		{
			std::cout << "============ BATTLE BETWEEN " << name1 << " AND " << name2 << " HAS ENDED ============" << std::endl;
			this -> ~Battle();
		}
	}
	calc_dmg(unit1, unit2);
}

/*
void Battle::get_names()
{
	std::cout << "What is the name of Player 1's unit?" << std::endl;
	std::cin >> name1;
	std::cout << "What is the name of Player 2's unit?" << std::endl;
	std::cin >> name2;
}
*/

void Battle::get_battle_conditions()
{
	std::cout << " PLAINS = 0, FOREST = 1, UNEVEN = 2, SWAMP = 3, TALGRS = 4" << std::endl;
	std::cout << "What terrain is " << name1 << " fighting on?" << std::endl;
	std::cin >> terrain1;
	std::cout << "What terrain is " << name2 << " fighting on?" << std::endl;
	std::cin >> terrain2;
	std::cout << " FLAT = 0, GENTLE = 1, MEDIUM = 2, HIGH = 3" << std::endl;
	std::cout << "What slope is " << name1 << " fighting on?" << std::endl;
	std::cin >> slope1;
	std::cout << "What slope is " << name2 << " fighting on?" << std::endl;
	std::cin >> slope2;
	if (terrain1 > 4 || terrain2 > 4 || slope1 > 3 || slope2 > 3)
	{
		std::cout << "-----Invalid number detected. Please try again. Carefully.-----" << std::endl;
			get_battle_conditions();
	}
}

const int Battle::get_type_readout(Unit& unit)
{	

	int var =  unit.give_type_readout();
	
	std::cin.get();
	std::cout << "-----Type readout gotten-----" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Type is " << var << std::endl;
	return var;
}

const int Battle::get_stats_readout(Unit& unit, int stat)
{
	int var = unit.give_stats_readout(stat);

	std::cin.get();
	std::cout << "-----Stat gotten-----" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Stat is " << var << std::endl;
	return var;
}

const bool Battle::get_is_ranged(Unit& unit)
{
	bool var = unit.give_is_ranged();

	std::cin.get();
	std::cout << "-----Is_ranged gotten-----" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Is_ranged is " << var << std::endl;
	return var;
}

void Battle::get_is_active_ranged()
{
	if (ranged1 == 1)
	{
		std::cout << "Is" << name1 << "fighting this battle ranged?" << std::endl;
		std::cout << "YES: 1, NO: 0" << std::endl;
		bool var1;
		std::cin >> var1;
		if (var1 == 1)
		{
			active_ranged1 = 1;
		}
		else if (var1 == 0)
		{
			active_ranged1 = 0;
		}

		std::cout << "-----Is_active_ranged 1 gotten-----" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "Is_active_ranged is " << active_ranged1 << std::endl;
	}
	else
	{
		std::cout << name1 << "is not ranged." << std::endl;
		std::cout << "\n" << std::endl;
	}
	

	if (ranged2 == 1)
	{
		std::cout << "Is" << name2 << "fighting this battle ranged?" << std::endl;
		std::cout << "YES: 1, NO: 0" << std::endl;
		bool var2;
		std::cin >> var2;
		if (var2 == 1)
		{
			active_ranged2 = 1;
		}
		else if (var2 == 0)
		{
			active_ranged2 = 0;
		}

		std::cout << "-----Is_active_ranged 2 gotten-----" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "Is_active_ranged is " << active_ranged2 << std::endl;
	}
	else
	{
		std::cout << name2 << "is not ranged." << std::endl;
		std::cout << "\n" << std::endl;
	}
	
	
}

int Battle::get_stuff(Unit& unit1, Unit& unit2)
{
	//get_names();
	get_battle_conditions();



	type1 = get_type_readout(unit1);
	ranged1 = get_is_ranged(unit1);
	for (int i = 2; i <= 4; i++)
		array1[i-2] = get_stats_readout(unit1, i);


	type2 = get_type_readout(unit2);
	ranged2 = get_is_ranged(unit2);
	for (int i = 2; i <= 4; i++)
		array2[i-2] = get_stats_readout(unit2, i);

	get_is_active_ranged();

	std::map<int, std::string> statDict;
	statDict[0] = (std::string("Number of soldiers"));
	statDict[1] = (std::string("Morale"));
	statDict[2] = (std::string("Firepower"));

	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << statDict[i] << ": " << array1[i] << " and " << array2[i] << std::endl;
	}
	return 0; //temporary
}



void Battle::calc_dmg(Unit& unit1, Unit& unit2)
{
	int terrain_mod1;
	int slope_mod1;
	int type_mod1;
	std::string cus_name1 = name1;

	int terrain_mod2;
	int slope_mod2;
	int type_mod2;
	std::string cus_name2 = name2;

	unit1.dmg_calc(terrain_mod1, slope_mod1, type_mod1, active_ranged1, type2, terrain1, slope1, cus_name1);
	unit2.dmg_calc(terrain_mod2, slope_mod2, type_mod2, active_ranged2, type1, terrain2, slope2, cus_name2);

	int is_alive1 = unit1.update_stats();
	int is_alive2 = unit2.update_stats();

	if (is_alive1 == 0 || is_alive2 == 0)
	{
		std::cout << "============ BATTLE BETWEEN " << name1 << " AND " << name2 << " HAS ENDED ============" << std::endl;
		this -> ~Battle();
	}
}