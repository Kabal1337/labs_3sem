#include "Military.h"
#include <vector>


Military::Military() {
	
}

Military::Military(const Military& mil)
{
	this->set_cap(mil.get_cap());
	this->set_max_speed(mil.get_max_speed());
	this->set_name(mil.get_name());
	this->set_team(mil.get_team());
	this->set_w_disp(mil.get_w_disp());
	this->set_wep(mil.get_wep());
	this->set_cargo_w(mil.get_cargo_w());
	this->set_speed();
}




Military::Military(const std::vector<Weaponry>& wep, unsigned cargo_w, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team)
	:Cargo(cargo_w, name, cap, w_dis, max_s, team), Secure(wep, name, cap, w_dis, max_s, team), Ship(name, cap, w_dis, max_s, team)
{

}
