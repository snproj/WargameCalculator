#include <iostream>;
#include "Manager.h"


void Manager::get_team_names()
{
	std::cout << "What is the name of Player 1's army?" << std::endl;
	std::cin >> team_name1;
	std::cout << "What is the name of Player 2's army?" << std::endl;
	std::cin >> team_name2;
}

Unit* Manager::create_Unit(int team_number)
{
	if (team_number == 1)
	{
		std::cout << "Create unit for " << team_name1 << " :" << std::endl;
	}
	else if (team_number == 2)
	{
		std::cout << "Create unit for " << team_name2 << " :" << std::endl;
	}

	std::cout << "ENTER UNIT NUMBER ACCORDING TO TABLE: " << std::endl;
	int unit_name = 0;
	std::cin >> unit_name;

	switch (unit_name)
	{
	case HAKSPR:
	{
		Unit* hakspr_ptr = new Hakespur;
		return hakspr_ptr;
		break;
	}
	default:
		std::cout << "ERROR: UNIT NOT RECOGNIZED" << std::endl;
		create_Unit(team_number);
	}

}

void Manager::deploy_army(int team_number)
{
	if (team_number == 1)
	{
		std::cout << "Deploying army for " << team_name1 << " :" << std::endl;
	}
	else if (team_number == 2)
	{
		std::cout << "Deploying army for " << team_name2 << " :" << std::endl;
	}

	bool cont_deployment;
	int array_counter = 0;

	do
	{
		if (team_number == 1)
		{
			unit_list1[array_counter] = create_Unit(team_number);
		}
		else if (team_number == 2)
		{
			unit_list2[array_counter] = create_Unit(team_number);
		}
		array_counter++;
		
		std::cout << "Would you like to create another unit?" << std::endl;
		std::cout << "YES: 1, NO: 0" << std::endl;
		std::cin >> cont_deployment;

	} while (cont_deployment == 1);
}

void Manager::destroy_Unit(Unit* unit_ptr)
{
	unit_ptr -> ~Unit;
}

void Manager::manager_routine()
{
	// ASSUMING ARMIES HAVE ALREADY BEEN DEPLOYED!


}