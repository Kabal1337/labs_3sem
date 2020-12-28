#pragma once

#include "Secure.h"
#include "Cargo.h"
class Military : public Cargo, public Secure
{
public:
	Military();
	Ship_type get_type() override
	{
		return(Mil);
	}

	Military(std::vector<Weaponry> wep, int cargo_w, std::string name, Captain& cap, int w_dis, int max_s, int team);




private:
	
};
