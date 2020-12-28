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
	/*Weaponry w;
	std::vector<Weaponry> wep1;
	wep1.push_back(w);
	std::vector<Weaponry> wep2;
	wep2 = wep1;
	wep1.clear();*/
	Weaponry w;
	std::vector<Weaponry> wep;
	wep.push_back(w);
	std::string anime = "anime";
	Captain cap;
	
	
	Convoy con;
	Secure* sec = new Secure(wep, "123", cap, 12, 12, 12);
	Cargo* car = new Cargo(12, "123", cap, 12, 12, 12);
	ship_info ship(sec, 12, "123");
	ship_info ship1(car, 12, "anime");
	std::vector<ship_info> v;
	con.add_ship(ship);
	con.add_ship(ship1);
	con.get_table_out();
	
	delete sec;	
	/*con.del_ship(0);
		try {
			con.get_ship_name(0);
		}
		catch (const char* a) {
			std::cout << a<<std::endl;
		}*/
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
