#include "Ship.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;



Ship::Ship() {
	this->name = "default";
	this->max_speed = 1;
	Captain cap;
	
	cap.name = "guy/girl";
	cap.experience = 0;
	cap.old = 21;
	cap.surname = "Cyber";
	cap.patronymic = "punk";
	this->cap = cap;
}
Ship::Ship(std::string name, Captain& cap, int w_dis, int max_s, int team)
{
	this->name = name;
	this->max_speed = max_s;
	this->cap = cap;
	
}










