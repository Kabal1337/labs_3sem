// lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Ship.h"
#include "Cargo.h"
#include <iostream>
#include "Captain.h";
#include "Secure.h"
#include "Military.h"
#include <vector>
#include "Сonvoy.h"
int main()
{
	
	Weaponry w;
	std::vector<Weaponry> wep;
	wep.push_back(w);
	std::string anime = "anime";
	Captain cap;
	cap.name = "lol";
	cap.old = 11;
	Convoy con;
	Ship* sec = new Secure(wep, "123", cap, 12, 0, 12);
	Ship* car = new Cargo(10, "123", cap, 12, 12, 12);
	Ship* car1 = new Cargo(9, "123", cap, 12, 12, 12);
	Ship* car2 = new Cargo(8, "123", cap, 12, 12, 12);
	//Ship* sec_temp;
	//if (1) {
	//	Cargo* temp_sec = dynamic_cast<Cargo*>(car);
	//	Cargo* temp = new Cargo(*temp_sec);
	//	sec_temp = temp;
	//	//delete temp_sec;
	//	//std::cout << temp.get_name();
	//}
	//std::cout<<sec_temp->get_name();
	/*std::string str = "kak";
	if (1) {
		std::string s = "cho";
		str = s;
	}
	std::cout << str;*/
	
	ship_info ship(sec, 12, "123");
	ship_info ship1(car, 12, "anime");
	//ship_info ship2(car1, 12, "anime");
	//ship_info ship3(car2, 12, "anime");
	
	//std::vector<ship_info> v;
	con.add_ship(ship);
	con.add_ship(ship1);
	//con.add_ship(ship2);
	//con.add_ship(ship3);
	con.get_table_out();
	//std::cout<<con.get_ship_name(0);
	std::cout << con.get_num_of_type_ships(Car) << std::endl;
	std::cout << con.get_con_speed() << std::endl;
	int indx = con.find_min_weight();
	std::cout <<con.get_weight(indx) << std::endl;
	con.add_cargo(10);
	std::cout << con.get_weight(indx) << std::endl;
	con.modern(1, 0);
	if (con.get_ship_info(1).get_ship()->get_type() == Mil) std::cout << "mil";
	//std::cout << con.get_con_speed();
	
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
