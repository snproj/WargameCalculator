#pragma once
#include <iostream>;
#include <string>;
#include <map>;



enum Unit_Stats
{
TYPE = 0,
NAME = 1,
NUMOFS = 2,
MORALE = 3,
FRPOWR = 4,
};

enum Unit_Type
{
	NOTYPE = 0,
	HAKSPR = 1,
	SPRMAN = 2,
	JAVELN = 3,
	ARCHER = 4,
	CRSBOW = 5,
	JAVCAV = 6,
	LANCAV = 7,
	MARCHR = 8,
	CATAPH = 9,
	GENERL = 10,
	LBALST = 11,
	HBALST = 12,
	STWTER = 13,
	AGREWS = 14,
	CLOFLR = 15,
	WARCHR = 16
};

class Unit
{
private:
	const int type = 0;

protected:
	std::string name;
	int number_of_soldiers;
	int morale;
	int firepower;
	bool is_ranged;

	int rout_count;
	bool is_routing;
	bool is_alive;

	void change_stat(std::string stat, int x);
	void change_stat(int stat, int x);

public:
	Unit();

	virtual ~Unit() = default;

	std::string give_name();

	virtual const int give_type_readout();
	const bool give_is_ranged();
	const int give_stats_readout(int stat);
	void take_dmg(int stat, int amt);

	void decrease_stat(int x, int amt);
	void increase_stat(int x, int amt);

	virtual int dmg_calc(int& terrain_mod, int& slope_mod, int& type_mod, bool& active_ranged1, int enemy_type, int terrain, int slope, std::string cus_name);

	int update_stats();

};