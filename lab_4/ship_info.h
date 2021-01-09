#pragma once
#include "Ship.h"
class ship_info
{
public:
	ship_info();///default constr
	ship_info(Ship* ship, unsigned distance, std::string Callsign);///ship_info constr
	
	~ship_info();///destructor
	Ship* get_ship() ///get ship pointer
	{
		return(ship);
	}

	void set_ship(Ship* ship) ///set ship pointer
	{
		this->ship = ship;
	}
	std::string get_callsign() ///get ship's callsign
	{
		return(Callsign);
	}
	int get_dist() {
		return distance;
	}
private:
	Ship* ship;
	std::string Callsign;
	int distance;
};





