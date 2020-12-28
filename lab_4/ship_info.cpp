#include "ship_info.h"
#include "Cargo.h"
#include "Secure.h"
#include "Military.h"

ship_info::ship_info(Ship* ship, int distance, std::string Callsign)
{
	Cargo* temp_car;
	Secure* temp_sec;
	Military* temp_mil;
	
	switch (ship->get_type())
	{
		
	case Car:
		temp_car = dynamic_cast<Cargo*>(ship);
		this->ship = new Cargo(temp_car->get_cargo_w(), temp_car->get_name(), temp_car->get_cap(),
			temp_car->get_w_disp(), temp_car->get_max_speed(), temp_car->get_team());
		
		break;
	case Sec:
		temp_sec = dynamic_cast<Secure*>(ship);
		
		this->ship = new Secure(temp_sec->get_wep(), temp_sec->get_name(), temp_sec->get_cap(),
			temp_sec->get_w_disp(), temp_sec->get_max_speed(), temp_sec->get_team());
		break;
	case Mil:
		temp_mil = dynamic_cast<Military*>(ship);
		this->ship = new Military(temp_mil->get_wep(), temp_mil->get_cargo_w(), temp_mil->get_name(), temp_mil->get_cap(),
			temp_mil->get_w_disp(), temp_mil->get_max_speed(), temp_mil->get_team());
		break;
		
	default:
		break;
	}
	this->distance = distance;
	this->Callsign = Callsign;
}

ship_info::~ship_info()
{
	//delete ship;
	ship = nullptr;
}
