#include <iostream>;
#include <string>;
#include "Unit_Class.h"
#include "Hakespur_Class.h"
#include "Terrain_Class.h"

Hakespur::Hakespur()
{
	type;

	std::cout << "What is the name of this " << type << "?" << std::endl;
	std::cin >> name;

	number_of_soldiers = 1000;
	morale = 1000;
	firepower = 200;
	is_ranged = 1;

	rout_count = 0;
	is_routing = 0;
	is_alive = 1;

	std::cout << "--- HAKESPUR UNIT CREATED ---" << std::endl;
}

const int Hakespur::give_type_readout()
{
	return type;
}

int Hakespur::dmg_calc(int& terrain_mod, int& slope_mod, int& type_mod, bool& active_ranged, int enemy_type, int terrain, int slope, std::string cus_name)
{
	std::cout << "///// HAKESPUR UNIT DMG_CALC \\\\\"" << std::endl;

	switch (terrain)
	{
	case PLAINS:
		break;

	case FOREST:
		terrain_mod = -(0.1 * number_of_soldiers);
		break;

	case UNEVEN:
		terrain_mod = -(0.2 * number_of_soldiers);
		break;

	case SWAMP:
		terrain_mod = -(0.1 * number_of_soldiers);
		break;

	case TALGRS:
		terrain_mod = -(0.2 * number_of_soldiers);
		break;
	}
	if (slope != FLAT)
	{
		std::cout << "Is " << cus_name << "fighting uphill or downhill?" << std::endl;
		std::cout << "UPHILL: 0, DOWNHILL: 1" << std::endl;
		bool up_or_down = 0;
		std::cin >> up_or_down;
		if (up_or_down == 0)
		{
			switch (slope)
			{
			case FLAT:
				break;

			case GENTLE:
				slope_mod = -(0.1 * number_of_soldiers);
				break;

			case MEDIUM:
				slope_mod = -(0.2 * number_of_soldiers);
				break;

			case HIGH:
				slope_mod = -(0.4 * number_of_soldiers);
				break;
			}
		}
		else
		{
			switch (slope)
			{
			case FLAT:
				break;

			case GENTLE:
				slope_mod = +(0.1 * number_of_soldiers);
				break;

			case MEDIUM:
				break;

			case HIGH:
				slope_mod = -(0.1 * number_of_soldiers);
				break;
			}
		}

	}
	switch (enemy_type)
	{
	default:
		break;
	}

	std::cout << "\\\\\ HAKESPUR UNIT DMG_CALC END /////" << std::endl;
	std::cout << std::endl;

	return 0; // temporary
}