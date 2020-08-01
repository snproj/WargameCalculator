#pragma once
#include <iostream>;
#include <string>;
#include "Battle_Class.h"
#include "Unit_Class.h"
#include "Hakespur_Class.h"
#include "Terrain_Class.h"

class Manager
{
private:
	Battle battle_list[100];

	Unit* unit_list1[100];
	Unit* unit_list2[100];

	std::string team_name1;
	std::string team_name2;


	void sort_into_teams();

public:
	void manager_routine();

	void get_team_names();

	Unit* create_Unit(int team_number);
	void destroy_Unit(Unit* unit_ptr);

	void deploy_army(int team_number);
};