#pragma once
#include <iostream>;
#include <string>;
#include "Unit_Class.h"

class Battle
{
private:
	int terrain1;
	int terrain2;
	int type1;
	int type2;
	int slope1;
	int slope2;
	std::string name1;
	std::string name2;
	int array1[3];
	int array2[3];
	bool ranged1;
	bool ranged2;
	bool active_ranged1;
	bool active_ranged2;
	bool init_flag;

	
	//int give_dmg(Unit& unit, int stat, int amt);
	//void get_names();

	

public:

	void battle_routine(Unit& unit1, Unit& unit2, bool init_flag);

	Battle(Unit& unit1, Unit& unit2);
	int get_stuff(Unit& unit1, Unit& unit2);
	void calc_dmg(Unit& unit1, Unit& unit2);

	void set_init_flag();
	
	void get_battle_conditions();
	virtual const int get_type_readout(Unit&  unit);
	const int get_stats_readout(Unit& unit, int stat);
	const bool get_is_ranged(Unit& unit);
	void get_is_active_ranged();

	//void service_units(Unit& unit1, Unit& unit2);
	
};