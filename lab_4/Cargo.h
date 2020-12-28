#pragma once
#include "Ship.h"

class Cargo : virtual public Ship
{
public:
	Cargo();
	
	
	Cargo(int cargo_w, std::string name, Captain& cap, int w_dis, int max_s, int team);
	Ship_type get_type() override
	{
		return(Car);
	}
	int get_cargo_w() {
		return(cargo_w);
	}
	void set_cargo_w(int cargo_w) {
		this->cargo_w = cargo_w;
	}
	double get_speed() {
		return(speed);
	}
	
private:
	int cargo_w;
	double speed;
};

