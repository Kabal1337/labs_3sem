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
	Ship(std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team);
	Ship(const Ship& ship);
	//virtual ~Ship() {}
	virtual Ship_type get_type() const = 0;	
	std::string get_name() const {
		return(name);
	}
	Captain get_cap() const {
		return(this->cap);
	}
	unsigned get_w_disp() const {
		return(w_displacement_m3);
	}
	unsigned get_max_speed() const {
		return(max_speed);
	}
	unsigned get_team() const {
		return(team);
	}
	void set_name(std::string name) {
		this->name = name;
	}
	void set_cap(const Captain& cap) {
		this->cap.experience = cap.experience;
		this->cap.name = cap.name;
		this->cap.old = cap.old;
		this->cap.patronymic = cap.patronymic;
		this->cap.surname = cap.surname;
	}
	void set_w_disp(unsigned w_displacement_m3) {
		this->w_displacement_m3 = w_displacement_m3;
	}
	void set_max_speed(unsigned max_speed) {
		this->max_speed = max_speed;
	}
	void set_team(unsigned team) {
		this->team=team;
	}

private:
	std::string name;
	Captain cap;
	unsigned w_displacement_m3;
	unsigned max_speed;
	unsigned team;
	
};
