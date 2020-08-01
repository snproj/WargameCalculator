#include <iostream>;
#include <string>;
#include "Unit_Class.h"
#include "Terrain_Class.h"


Unit::Unit()
{
	type;

	name = "DEFAULT";

	number_of_soldiers = 0;
	morale = 0;
	firepower = 0;
	is_ranged = 0;

	rout_count = 0;
	is_routing = 0;
	is_alive = 1;

	std::cout << "--- UNIT CREATED ---" << std::endl;
}

std::string Unit::give_name()
{
	return name;
}

void Unit::change_stat(std::string stat, int x)
{
	switch (x)
	{
		case 1:
			name = stat;
			std::cout << "Name changed to: " << stat << std::endl;
			break;
		default:
			std::cout << "UNIT::CHANGE_STAT WITH STRING ERROR!" << std::endl;
	}
}

void Unit::change_stat(int stat, int x)
{
	switch (x)
	{
		case 0:
			std::cout << "CANNOT CHANGE TYPE!" << std::endl;
			break;
		case 2:
			number_of_soldiers = stat;
			std::cout << "Number of soldiers changed to: " << stat << std::endl;
			break;
		case 3:
			morale = stat;
			std::cout << "Morale changed to: " << stat << std::endl;
			break;
		case 4:
			firepower = stat;
			std::cout << "Firepower changed to: " << stat << std::endl;
			break;
		default:
			std::cout << "UNIT::CHANGE_STAT WITH INT ERROR!" << std::endl;

	}
}

void Unit::decrease_stat(int x, int amt)
{
	switch (x)
	{
		case 2:
			number_of_soldiers += amt;
			if (number_of_soldiers < 0)
			{
				number_of_soldiers = 0;
			}
			std::cout << "Number of soldiers decreased to: " << number_of_soldiers << std::endl;
			break;
		case 3:
			morale += amt;
			if (morale < 0)
			{
				std::cout << "Massive rout!" << morale << std::endl;
			}
			std::cout << "Morale decreased to: " << morale << std::endl;
			break;
		case 4:
			firepower += amt;
			if (firepower < 0)
			{
				firepower = 0;
			}
			std::cout << "Firepower decreased to: " << firepower << std::endl;
			break;
		default:
			std::cout << "UNIT::DECREASE_STAT ERROR!" << std::endl;
	}
}

void Unit::increase_stat(int x, int amt)
{
	switch (x)
	{
	case 2:
		number_of_soldiers += amt;
		std::cout << "Number of soldiers increased to: " << number_of_soldiers << std::endl;
		break;
	case 3:
		morale += amt;
		std::cout << "Morale increased to: " << morale << std::endl;
		break;
	case 4:
		firepower += amt;
		std::cout << "Firepower increased to: " << firepower << std::endl;
		break;
	default:
		std::cout << "UNIT::INCREASE_STAT ERROR!" << std::endl;
	}
}

const int Unit::give_type_readout()
{
	return type;
}

const bool Unit::give_is_ranged()
{
	return is_ranged;
}

const int Unit::give_stats_readout(int stat)
{
	switch (stat)
	{
	case 2:
		return number_of_soldiers;
		std::cout << "NOS" << std::endl;
		break;
	case 3:
		return morale;
		std::cout << "MOR" << std::endl;
		break;
	case 4:
		return firepower;
		std::cout << "FPW" << std::endl;
		break;
	default:
		std::cout << "UNIT::GIVE_STATS_READOUT ERROR!" << std::endl;
	};
}

void Unit::take_dmg(int stat, int amt)
{
	if (amt < 0)
	{
		decrease_stat(stat, amt);
	}
	else if (amt > 0)
	{
		increase_stat(stat, amt);
	}
	else
	{
		std::cout << "UNIT::TAKE_DMG ERROR - AMT MAY EQUAL 0" << std::endl;
	}
}

int Unit::dmg_calc(int& terrain_mod, int& slope_mod, int& type_mod, bool& active_ranged, int enemy_type, int terrain, int slope, std::string cus_name)
{
	std::cout << "///// DEFAULT UNIT DMG_CALC \\\\\"" << std::endl;

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

	std::cout << "\\\\\ DEFAULT UNIT DMG_CALC END /////" << std::endl;
	std::cout << std::endl;

	return 0; // temporary
}

int Unit::update_stats()
{

	if (rout_count > 0)
	{
		rout_count -= 1;
		morale += 100;

		if (rout_count == 0)
		{
			is_routing = 0;
			std::cout << name << "has stopped routing!" << std::endl;
		}
	}
	else if (morale < 0)
	{
		is_routing = 1;
		std::cout << name << "is routing!" << std::endl;

		rout_count = -morale;
		std::cout << "ROUT COUNT: " << rout_count << std::endl;
	}

	if (number_of_soldiers <= 0)
	{
		is_alive = 0;
		std::cout << name << "has been wiped out!" << std::endl;
	}

	if (is_alive == 1) return 1;
	else return 0;
}