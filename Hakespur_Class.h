#pragma once
#include <iostream>;
#include <string>;

class Hakespur : public Unit
{
private:
	const int type = HAKSPR;
public:
	Hakespur();
	~Hakespur() = default;

	const int give_type_readout();
	int dmg_calc(int& terrain_mod, int& slope_mod, int& type_mod, bool& active_ranged1, int enemy_type, int terrain, int slope, std::string cus_name);
};