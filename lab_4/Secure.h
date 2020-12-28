#pragma once
#include "Ship.h"
#include "Weaponry.h"
#include "Secure.h"
#include "Cargo.h"
#include <vector>
class Secure: virtual public Ship
{
public:
	
	Secure(std::vector<Weaponry> wep, std::string name, Captain& cap, int w_dis, int max_s, int team);
	Ship_type get_type() override
	{
		return(Sec);
	}
	std::vector<Weaponry> get_wep() {
		return(wep);
	}
	
	Secure();
private:
	
	std::vector<Weaponry> wep;
};

