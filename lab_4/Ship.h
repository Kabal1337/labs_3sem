#pragma once
#include <string>
#include "Captain.h"
enum Ship_type {
	
	Car,
	Sec,
	Mil
};

class Ship
{
public:
	Ship();
	Ship(std::string name, Captain& cap, int w_dis, int max_s, int team);
	
	virtual Ship_type get_type() = 0;	
	std::string get_name() {
		return(name);
	}
	Captain& get_cap() {
		return(cap);
	}
	int get_w_disp() {
		return(w_displacement_m3);
	}
	int get_max_speed() {
		return(max_speed);
	}
	int get_team() {
		return(team);
	}
	void set_name(std::string name) {
		this->name = name;
	}
	void set_cap(Captain& cap) {
		this->cap=cap;
	}
	void set_w_disp(int w_displacement_m3) {
		this->w_displacement_m3 = w_displacement_m3;
	}
	void set_max_speed(int max_speed) {
		this->max_speed = max_speed;
	}
	void set_team(int team) {
		this->team=team;
	}

protected:
	std::string name;
	Captain cap;
	int w_displacement_m3;
	int max_speed;
	int team;
	
};
