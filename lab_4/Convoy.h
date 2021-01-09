#pragma once
#include <vector>
//#include <string>
#include "Ship.h"
#include "ship_info.h"
#include "My_vector.h"

class Convoy
{
public:
	Convoy() ///defualt constr
	{
		Captain cap;
		this->con_cap = cap;
		this->Start = 0;
		this->Fin = 0;
		this->distance = 0;
	}
	std::string get_ship_name(unsigned el); ///get ship name by index
	void add_ship(ship_info& el); /// add ship in the table
	void del_ship(unsigned el); /// del ship by index
	int get_num_of_type_ships(Ship_type ty); ///get number of ships of different types
	ship_info& get_ship_info(std::string Callsign);///get ship_info by callsign
	int get_num_ship();///get number of ships in the table
	void get_table_out(); ///get table out 
	int get_con_speed();///get convoy's speed
	void add_cargo(unsigned weight); /// add more cargo 
	int find_min_weight(); ///find ship with minimal weight, return index
	int get_weight(unsigned index); ///get weight of ship by index
	ship_info& get_ship_info(unsigned index); ///get ship_info by index
	void modern(unsigned index_car, unsigned index_wep);///modernize the ship by weaponary from one of secure of military ships;
	void set_cap(Captain& cap);///set captain of convoy
	void set_start(int start);///set start convoy's point
	void set_fin(int fin);///set finish convoy's point
	void set_dist(unsigned dist);///set convoy's distant 
private:
	My_vector<ship_info> con;
	Captain con_cap;
	int Start;
	int Fin;
	unsigned distance;
};



