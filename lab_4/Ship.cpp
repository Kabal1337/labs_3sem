#include "Ship.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;



Ship::Ship() {
	this->name = "default";
	this->max_speed = 1;
	Captain cap;
	this->cap = cap;
}
Ship::Ship(std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team)
{
	this->team = team;
	this->name = name;
	this->max_speed = max_s;
	this->cap = cap;
	this->w_displacement_m3 = w_dis;

	
}

Ship::Ship(const Ship& ship)
{
	this->set_cap(ship.cap);
	this->max_speed = ship.max_speed;
	this->name = ship.name;
	this->team = ship.team;
	this->w_displacement_m3 = ship.w_displacement_m3;

}










