#include "Secure.h"



Secure::Secure(std::vector<Weaponry> wep, std::string name, Captain& cap, int w_dis, int max_s, int team) :Ship(name, cap, w_dis, max_s, team)
{
	this->wep = wep;
}





Secure::Secure()
{
	Captain cap;
	cap.experience = 0;
	cap.name = "null";
	cap.old = 0;
	cap.patronymic = "null";
	cap.surname = "null";
	this->name = "null";
	this->max_speed = 0;
	this->cap = cap;
	
}
