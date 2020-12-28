#include "Cargo.h"

Cargo::Cargo()
{
	
	speed = 0;
	cargo_w = 0;
}


Cargo::Cargo(int cargo_w, std::string name, Captain& cap, int w_dis, int max_s, int team)
	:Ship(name, cap, w_dis, max_s, team) {
	this->cargo_w = cargo_w;
	this->speed = (max_s / cargo_w) * 10;
}
