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
	Ship();///defualt constr
	Ship(std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team);///Ship constr
	Ship(const Ship& ship);///copy constr
	//virtual ~Ship() {}
	virtual Ship_type get_type() const = 0;	 ///virtual method for getting ship's type
	std::string get_name() const ///get ships's name
	{ 
		return(name);
	}
	Captain get_cap() const ///get cap's information
	{
		return(this->cap);
	}
	unsigned get_w_disp() const ///get water displacement
	{
		return(w_displacement_m3);
	}
	unsigned get_max_speed() const ///get max speed
	{
		return(max_speed);
	}
	unsigned get_team() const ///get number of team members
	{
		return(team);
	}
	void set_name(std::string name) ///set ship's name
	{
		this->name = name;
	}
	void set_cap(const Captain& cap) ///set captain
	{
		this->cap.experience = cap.experience;
		this->cap.name = cap.name;
		this->cap.old = cap.old;
		this->cap.patronymic = cap.patronymic;
		this->cap.surname = cap.surname;
	}
	void set_w_disp(unsigned w_displacement_m3) ///set water displacement
	{
		this->w_displacement_m3 = w_displacement_m3;
	}
	void set_max_speed(unsigned max_speed) ///set max speed
	{
		this->max_speed = max_speed;
	}
	void set_team(unsigned team) ///set number of team members
	{
		this->team=team;
	}

private:
	std::string name;
	Captain cap;
	unsigned w_displacement_m3;
	unsigned max_speed;
	unsigned team;
	
};
