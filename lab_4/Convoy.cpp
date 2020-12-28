#include "Ñonvoy.h"
#include <string>
#include "Military.h"
#include <iostream>
std::string Convoy::get_ship_name(int el) {
	
	auto it = con.begin() + el;
	Ship* sh =it->get_ship();
	if (it == con.end()) throw "Invalid index";
	return(sh->get_name());
	//it = con.begin() + el;
	//return(it)

}
void Convoy::add_ship(ship_info& el) {
	
	con.push_back(el);
}
void Convoy::del_ship(int el) {
	std::vector<ship_info>::iterator it;

	it = con.begin() + el;
	if (it >= con.end()) throw "out of range";
	con.erase(it);
}
int Convoy::get_num_of_type_ships(Ship_type ty)
{	
	if (ty == Car) {
		int temp = 0;
		auto it = con.begin();
		
		while (it != con.end()) {
			Cargo* car = dynamic_cast<Cargo*>(it->get_ship());
			if (car->get_type()==Car) temp++;
			it++;
		}
		return temp;
	}
	if (ty == Sec)
	{
		int temp = 0;
		auto it = con.begin();
		while (it != con.end()) {
			Secure* sec = dynamic_cast<Secure*>(it->get_ship());
			if (sec->get_type() == Sec) temp++;
			it++;
		}
		return temp;
	}
	if (ty == Mil)
	{
		int temp = 0;
		auto it = con.begin();
		while (it != con.end()) {
			Military* mil = dynamic_cast<Military*>(it->get_ship());
			if (mil->get_type() == Mil) temp++;
			it++;
		}
		return temp;
	}
	return 0;
}

ship_info Convoy::get_ship_info(std::string Callsign)
{
	auto it = con.begin();
	while (it != con.end()) {
		if (it->get_callsign() == Callsign) {
			return(*it);
		}
	}
}

int Convoy::get_num_ship()
{
	int temp = 0;
	auto it = con.begin();
	while (it != con.end()) {
		temp++;
	}
	return temp;
}

void Convoy::get_table_out()
{
	int temp = 0;
	for (auto it = con.begin(); it!=con.end(); it++)
	{
		
		std::cout <<temp<<": "<< it->get_callsign()<<std::endl;
		temp++;
	} 
	
}
