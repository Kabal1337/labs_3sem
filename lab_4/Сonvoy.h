#pragma once
#include <vector>
//#include <string>
#include "Ship.h"
#include "ship_info.h"


class Convoy
{
public:
	
	std::string get_ship_name(int el);
	void add_ship(ship_info& el);
	void del_ship(int el);
	int get_num_of_type_ships(Ship_type ty);
	ship_info get_ship_info(std::string Callsign);
	int get_num_ship();
	void get_table_out();
private:
	std::vector<ship_info> con;
};



