#pragma once
#include "Ship.h"

class Cargo : virtual public Ship
{
public:
	Cargo();///Default constr
	
	
	Cargo(unsigned cargo_w, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team);///Cargo constr
	Cargo(const Cargo& car);///copy constr
	Ship_type get_type() const override ///get type of ship
	{
		return(Car);
	}
	unsigned get_cargo_w() const///get cargo's weight
	{
		return(cargo_w);
	}
	void set_cargo_w(unsigned cargo_w)  ///set cargo's weight
	{
		this->cargo_w = cargo_w;
		if (cargo_w != 0)
			this->speed = (get_max_speed() / cargo_w) * 10;
		else this->speed = get_max_speed();
	}
	void set_speed()/// set speed(weight)
	{ 
		speed=(get_max_speed() / get_cargo_w()) * 10;
	}
	unsigned get_speed() const /// get speed(weight)
	{ 
		return(speed);
	}
	
private:
	unsigned cargo_w;
	unsigned speed;
};

