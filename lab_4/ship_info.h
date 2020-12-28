#pragma once
#include "Ship.h"
class ship_info
{
public:
	ship_info(Ship* ship, int distance, std::string Callsign);
	~ship_info();
	Ship* get_ship() {
		return(ship);
	}
	std::string get_callsign() {
		return(Callsign);
	}
private:
	Ship* ship;
	std::string Callsign;
	int distance;
};





