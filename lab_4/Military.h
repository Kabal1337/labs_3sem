#pragma once

#include "Secure.h"
#include "Cargo.h"
class Military : public Cargo, public Secure
{
public:
	Military();
	Military(const Military& mil);
	Ship_type get_type() const override
	{
		return(Mil);
	}

	Military(const std::vector<Weaponry>& wep, unsigned cargo_w, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team);
	



private:
	
};
