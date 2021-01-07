#pragma once
#include <vector>
//#include <string>
#include "Ship.h"
#include "ship_info.h"
#include "My_vector.h"

class Convoy
{
public:
	
	std::string get_ship_name(int el);
	void add_ship(ship_info& el);
	void del_ship(int el);
	int get_num_of_type_ships(Ship_type ty);
	ship_info& get_ship_info(std::string Callsign);
	int get_num_ship();
	void get_table_out();
	int get_con_speed();
	void add_cargo(int weight);
	int find_min_weight();
	int get_weight(int index);
	ship_info& get_ship_info(unsigned index);
	void modern(unsigned index_car, unsigned index_wep);
private:
	My_vector<ship_info> con;
};



