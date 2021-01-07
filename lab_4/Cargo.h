#pragma once
#include "Ship.h"

class Cargo : virtual public Ship
{
public:
	Cargo();
	
	
	Cargo(unsigned cargo_w, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team);
	Cargo(const Cargo& car);
	Ship_type get_type() const override
	{
		return(Car);
	}
	unsigned get_cargo_w() const{
		return(cargo_w);
	}
	void set_cargo_w(unsigned cargo_w) {
		this->cargo_w = cargo_w;
	}
	void set_speed() {
		speed=(get_max_speed() / get_cargo_w()) * 10;
	}
	unsigned get_speed() const {
		return(speed);
	}
	
private:
	unsigned cargo_w;
	unsigned speed;
};

