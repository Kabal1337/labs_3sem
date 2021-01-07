#include "Сonvoy.h"
#include <string>
#include "Military.h"
#include <iostream>
std::string Convoy::get_ship_name(int el) {
	
	
	if (el>=con.size()) throw "Invalid index";
	Ship* sh = con[el].get_ship();
	
	return(sh->get_name());
	//it = con.begin() + el;
	//return(it)

}
void Convoy::add_ship(ship_info& el) {
	//std::cout<<el.get_ship()->get_name();
	con.push_back(el);
}
void Convoy::del_ship(int el) {
	
	if (el>=con.size()) throw "out of range";
	con.erase(el);
}
int Convoy::get_num_of_type_ships(Ship_type ty)
{	
	if (ty == Car) {
		int temp = 0;
		
		
		for (int i = 0; i < con.size(); i++)
		{
			//Cargo* car = dynamic_cast<Cargo*>(con[i].get_ship());
			
			if (con[i].get_ship()->get_type() ==Car) temp++;
			
		}
		return temp;
	}
	if (ty == Sec)
	{
		int temp = 0;
		for (int i = 0; i < con.size(); i++)
		{
			//std::cout << con[i].get_ship()->get_name();
			if (con[i].get_ship()->get_type() == Sec) temp++;

		}
		
		return temp;
	}
	if (ty == Mil)
	{
		int temp = 0;
		for (int i = 0; i < con.size(); i++)
		{
			//Military* car = dynamic_cast<Military*>(con[i].get_ship());
			if (con[i].get_ship()->get_type() == Mil) temp++;

		}
		return temp;
	}
	return 0;
}

ship_info& Convoy::get_ship_info(std::string Callsign)
{
	
	for(int i = 0; i<con.size(); i++) {
		if (con[i].get_callsign() == Callsign) {
			return(con[i]);
		}
	}
}

int Convoy::get_num_ship()
{
	return(con.size());
}

void Convoy::get_table_out()
{
	int temp = 0;
	for (int i = 0; i < con.size(); i++)
	{
		
		std::cout <<temp<<": "<< con[i].get_callsign()<<std::endl;
		temp++;
	} 
	
}

int Convoy::get_con_speed()
{
	unsigned temp = 0;
	if (con.size() != 0) {
		if (con[0].get_ship()->get_type() == Car) {
			Cargo* temp_p = dynamic_cast<Cargo*>(con[0].get_ship());
			temp = temp_p->get_speed();
		}
		if (con[0].get_ship()->get_type() == Sec) {
			Secure* temp_p = dynamic_cast<Secure*>(con[0].get_ship());
			temp = temp_p->get_max_speed();
		}
		if (con[0].get_ship()->get_type() == Mil) {
			Military* temp_p = dynamic_cast<Military*>(con[0].get_ship());
			temp = temp_p->get_speed();
		}


		for (int i = 0; i < con.size(); i++)
		{
			if (con[i].get_ship()->get_type() == Car) {
				Cargo* temp_p = dynamic_cast<Cargo*>(con[i].get_ship());
				if (temp_p->get_speed() < temp) temp = temp_p->get_speed();
			}
			if (con[i].get_ship()->get_type() == Sec) {
				Secure* temp_p = dynamic_cast<Secure*>(con[i].get_ship());
				if (temp_p->get_max_speed() < temp) temp = temp_p->get_max_speed();
			}
			if (con[i].get_ship()->get_type() == Mil) {
				Military* temp_p = dynamic_cast<Military*>(con[i].get_ship());
				if (temp_p->get_speed() < temp) temp = temp_p->get_speed();
			}
		}
	}
	return temp;
}

void Convoy::add_cargo(int weight)
{	
	for (int i = 1; i <= weight; i++)
	{
		int min_w = 0;
		try {
			min_w = find_min_weight();
		}
		catch (char* a) {
			std::cout << a;
		}

		
		if (con[min_w].get_ship()->get_type() == Car)
		{
			Cargo* car = dynamic_cast<Cargo*>(con[min_w].get_ship());
			car->set_cargo_w(car->get_cargo_w() + 1);
		}
		if (con[min_w].get_ship()->get_type() == Mil)
		{
			Military* mil = dynamic_cast<Military*>(con[min_w].get_ship());
			mil->set_cargo_w(mil->get_cargo_w() + 1);
		}
	}
	
	
}

int Convoy::find_min_weight()
{
	unsigned index = 0;
	unsigned t = 0;
	unsigned temp = 0;
	if (con.size() != 0) {
		for (int j = 0; j < con.size(); j++)
		{	
			if ((con[j].get_ship()->get_type() == Car) || (con[j].get_ship()->get_type() == Mil)) {
				if (con[j].get_ship()->get_type() == Car) {
					Cargo* temp_p = dynamic_cast<Cargo*>(con[j].get_ship());
					temp = temp_p->get_cargo_w();
					index = j;
				}

				if (con[j].get_ship()->get_type() == Mil) {
					Military* temp_p = dynamic_cast<Military*>(con[j].get_ship());
					temp = temp_p->get_cargo_w();
					index = j;
				}
				t = j;
				break;
			}
			if (j == con.size()-1) throw "no cargo ships";
					
		}
		

		for (int i = t; i < con.size(); i++)
		{
			if (con[i].get_ship()->get_type() == Car) {
				Cargo* temp_p = dynamic_cast<Cargo*>(con[i].get_ship());
				if (temp_p->get_cargo_w() < temp)
				{
					temp = temp_p->get_cargo_w();
					index = i;
				}
			}
			
			if (con[i].get_ship()->get_type() == Mil) {
				Military* temp_p = dynamic_cast<Military*>(con[i].get_ship());
				if (temp_p->get_cargo_w() < temp) {
					temp = temp_p->get_cargo_w();
					index = i;
				}
			}
		}
	}
	return index;
}

int Convoy::get_weight(int index)
{
	if (con[index].get_ship()->get_type() == Car) {
		Cargo* temp = dynamic_cast<Cargo*>(con[index].get_ship());
		return(temp->get_cargo_w());
	}
	if (con[index].get_ship()->get_type() == Mil) {
		Military* temp = dynamic_cast<Military*>(con[index].get_ship());
		return(temp->get_cargo_w());
	}
	if (con[index].get_ship()->get_type() == Sec) throw "Cant put cargo";
}

ship_info& Convoy::get_ship_info(unsigned index)
{
	return(con[index]);
	// TODO: вставьте здесь оператор return
}

void Convoy::modern(unsigned index_car, unsigned index_wep)
{
	if ((con[index_car].get_ship()->get_type() != Car) ||
		(index_car>=con.size()) || (index_wep >= con.size())
		|| ((con[index_wep].get_ship()->get_type() != Mil) && 
			(con[index_wep].get_ship()->get_type() != Sec))) throw "invalid index";
	if (con[index_wep].get_ship()->get_type() == Mil) {
		Military* mil = dynamic_cast<Military*>(con[index_wep].get_ship());
		Military* mil_new = new Military;
		Cargo* car = dynamic_cast<Cargo*>(con[index_car].get_ship());
		mil_new->set_cap(car->get_cap());
		mil_new->set_cargo_w(car->get_cargo_w());
		mil_new->set_max_speed(car->get_max_speed());
		mil_new->set_name(car->get_name());
		mil_new->set_speed();
		mil_new->set_team(car->get_team());
		mil_new->set_wep(mil->get_wep());
		mil_new->set_w_disp(mil->get_w_disp());
		delete car;
		con[index_car].set_ship(mil_new);
	}
	if (con[index_wep].get_ship()->get_type() == Sec) {
		Secure* mil = dynamic_cast<Secure*>(con[index_wep].get_ship());
		Military* mil_new = new Military;
		Cargo* car = dynamic_cast<Cargo*>(con[index_car].get_ship());
		mil_new->set_cap(car->get_cap());
		mil_new->set_cargo_w(car->get_cargo_w());
		mil_new->set_max_speed(car->get_max_speed());
		mil_new->set_name(car->get_name());
		mil_new->set_speed();
		mil_new->set_team(car->get_team());
		mil_new->set_wep(mil->get_wep());
		mil_new->set_w_disp(car->get_w_disp());
		delete car;
		con[index_car].set_ship(mil_new);
	}
}
