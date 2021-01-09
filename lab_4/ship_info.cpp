#include "ship_info.h"
#include "Cargo.h"
#include "Secure.h"
#include "Military.h"

ship_info::ship_info()
{
	this->ship = nullptr;
	this->distance = 0;
	this->Callsign = "null";
}

ship_info::ship_info(Ship* ship, unsigned distance, std::string Callsign) 
{
	//Cargo* temp_car;
	//Secure* temp_sec;
	//Military* temp_mil;




	if (ship->get_type() == Car)
	{
		Cargo* temp_car = dynamic_cast<Cargo*>(ship);
		Cargo* car = new Cargo(*temp_car);
		this->ship = car;
	}
	if (ship->get_type() == Sec) {
		Secure* temp_sec = dynamic_cast<Secure*>(ship);
		Secure* sec = new Secure(*temp_sec);
		this->ship = sec;
	}
		
	if (ship->get_type() == Mil) {
		Military* temp_mil = dynamic_cast<Military*>(ship);
		Military* mil = new Military(*temp_mil);
		this->ship = mil;
	}

	
	this->distance = distance;
	this->Callsign = Callsign;
}

ship_info::~ship_info()
{
	//delete ship;
	
}
