#include "Military.h"
#include <vector>


Military::Military() {
	
}

Military::Military(std::vector<Weaponry> wep,int cargo_w, std::string name, Captain& cap, int w_dis, int max_s, int team)
	:Cargo(cargo_w, name, cap, w_dis, max_s, team), Secure(wep, name, cap, w_dis, max_s, team), Ship(name, cap, w_dis, max_s, team)
{

}
