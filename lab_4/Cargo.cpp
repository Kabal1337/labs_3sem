#include "Cargo.h"

Cargo::Cargo()
{
	
	speed = 0;
	cargo_w = 0;
}


Cargo::Cargo(unsigned cargo_w, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team)
	:Ship(name, cap, w_dis, max_s, team) {
	this->cargo_w = cargo_w;
	if (cargo_w != 0)
		this->speed = (max_s / cargo_w) * 10;
	else this->speed = max_s;
}

Cargo::Cargo(const Cargo& car)
{
	this->set_cap(car.get_cap());
	this->set_max_speed(car.get_max_speed());
	this->set_name(car.get_name());
	this->set_team(car.get_team());
	this->set_w_disp(car.get_w_disp());
	this->cargo_w=car.get_cargo_w();
	this->speed = car.get_speed();
}
