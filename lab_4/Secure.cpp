#include "Secure.h"



Secure::Secure(const std::vector<Weaponry>& wep, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team) 
	:Ship(name, cap, w_dis, max_s, team)
{
	this->wep = wep;
}

Secure::Secure(const Secure& sec)
{	
	this->set_cap(sec.get_cap());
	this->set_max_speed(sec.get_max_speed());
	this->set_name(sec.get_name());
	this->set_team(sec.get_team());
	this->set_w_disp(sec.get_w_disp());
	this->wep = sec.wep;
}





Secure::Secure()
{
	Captain cap;
	cap.experience = 0;
	cap.name = "null";
	cap.old = 0;
	cap.patronymic = "null";
	cap.surname = "null";
	this->set_name("null");
	this->set_max_speed(0);
	this->set_cap(cap);
	
}
