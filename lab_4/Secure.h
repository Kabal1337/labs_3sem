#pragma once
#include "Ship.h"
#include "Weaponry.h"
#include "Secure.h"
#include "Cargo.h"
#include <vector>
class Secure: virtual public Ship
{
public:
	
	Secure(const std::vector<Weaponry>& wep, std::string name, const Captain& cap, unsigned w_dis, unsigned max_s, unsigned team);///Secure constr
	Secure(const Secure& sec); ///copy constr
	Ship_type get_type() const override
	{
		return(Sec);
	}
	void shoot(int index) ///make a shoot, ammo--;
	{ 
		if (index >= wep.size()) throw "invalid index";
		if (wep[index].ammo == 0) throw "ammo is empty";
		wep[index].ammo--;
	}
	void set_wep(const std::vector<Weaponry>& wep) ///set a weaponary
	{
		this->wep = wep;
	}
	std::vector<Weaponry> get_wep() const  ///get weaponary
	{
		return(wep);
	}
	
	Secure(); ///default constr
private:
	
	std::vector<Weaponry> wep;
};

