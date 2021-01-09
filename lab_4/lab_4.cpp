// lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Ship.h"
#include "Cargo.h"
#include <iostream>
#include "Captain.h";
#include "Secure.h"
#include "Military.h"
#include <vector>
#include "Convoy.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	//
	//Weaponry w;
	//std::vector<Weaponry> wep;
	//wep.push_back(w);
	//std::string anime = "anime";
	//Captain cap;
	//cap.name = "lol";
	//cap.old = 11;
	//Convoy con;
	//Ship* sec = new Secure(wep, "123", cap, 12, 0, 12);
	//Ship* car = new Cargo(10, "123", cap, 12, 12, 12);
	//Ship* car1 = new Cargo(9, "123", cap, 12, 12, 12);
	//Ship* car2 = new Cargo(8, "123", cap, 12, 12, 12);
	////Ship* sec_temp;
	////if (1) {
	////	Cargo* temp_sec = dynamic_cast<Cargo*>(car);
	////	Cargo* temp = new Cargo(*temp_sec);
	////	sec_temp = temp;
	////	//delete temp_sec;
	////	//std::cout << temp.get_name();
	////}
	////std::cout<<sec_temp->get_name();
	///*std::string str = "kak";
	//if (1) {
	//	std::string s = "cho";
	//	str = s;
	//}
	//std::cout << str;*/
	//
	//ship_info ship(sec, 12, "123");
	//ship_info ship1(car, 12, "anime");
	////ship_info ship2(car1, 12, "anime");
	////ship_info ship3(car2, 12, "anime");
	//
	////std::vector<ship_info> v;
	//con.add_ship(ship);
	//con.add_ship(ship1);
	////con.add_ship(ship2);
	////con.add_ship(ship3);
	//con.get_table_out();
	////std::cout<<con.get_ship_name(0);
	//std::cout << con.get_num_of_type_ships(Car) << std::endl;
	//std::cout << con.get_con_speed() << std::endl;
	//int indx = con.find_min_weight();
	//std::cout <<con.get_weight(indx) << std::endl;
	//con.add_cargo(10);
	//std::cout << con.get_weight(indx) << std::endl;
	//if (con.get_ship_info(1).get_ship()->get_type() == Mil) std::cout << "mil";
	//else std::cout << "no";
	//try {
	//	con.modern(1, 0);
	//}
	//catch (const char* a) {
	//	std::cerr << a << std::endl;
	//}
	//if (con.get_ship_info(1).get_ship()->get_type() == Mil) std::cout << "mil";
	////std::cout << con.get_con_speed();
	//
	//float length, r, x;
	int com_num = 0;
	
	Convoy con;
	
	float t;
	while (com_num != 8)
	{
		cout << "1.Creat ship" << endl
			<<"2.Add cargo"<<endl;
		
		cin >> com_num;

		

		switch (com_num)
		{
		case 1:
		{
			Captain cap;
			cout << "Enter caps info"<<endl;
			cout << "name: ";
			cin >> cap.name;
			cout << endl;
			cout << "old: ";
			cin >> cap.old;
			cout << endl;
			cout << "expirience: ";
			cin >> cap.experience;
			cout << endl;
			cout << "surname: ";
			cin >> cap.surname;
			cout << endl;
			cout << "patronymic: ";
			cin >> cap.patronymic;
			cout << endl;
			cout << "Enter ship's info" << endl<<"water dusplacement: ";
			unsigned disp;
				
			cin >> disp;
			cout << endl << "max speed: ";
			unsigned m_speed;
			cin >> m_speed;
			cout << endl << "number of team members: ";
			unsigned team;
			cin >> team;
			cout << endl << "name: ";
			std::string name;
			cin >> name;
			cout << endl << "Callsign: ";
			std::string Callsign;
			cin >>Callsign;
			cout << endl << "distance: ";
			unsigned dist;
			cin >> dist;
			cout << endl;
			cout << "Enter ship's param" << endl << "Choose type of ship:" << endl
				<< "1.Secure" << endl << "2.Cargo" << endl << "3.Military" << endl;
			unsigned type;
			cin >> type;
			Ship* ship;
			switch (type)
			{
			case(1): {
				Weaponry wep;
				std::vector<Weaponry> w;
				w.push_back(wep);
				
				ship = new Secure(w, name, cap, disp, m_speed, team);
				break;
			}
			case(2): {
				cout << "cargo_w: ";
				unsigned weight;
				cin >> weight;
				cout << endl;
				ship = new Cargo(weight, name, cap, disp, m_speed, team);
				break;
			}
			case(3): {
				Weaponry wep;
				std::vector<Weaponry> w;
				w.push_back(wep);
				cout << "cargo_w: ";
				unsigned weight;
				cin >> weight;
				cout << endl;
				ship = new Military(w, weight, name, cap, disp, m_speed, team);
				break;
			}
			
				   
			default:
				cout << "invalid type";
				return 0;
				break;
			}
			
			
			ship_info ship_inf(ship, dist, Callsign);
			
			con.add_ship(ship_inf);
			con.get_table_out();
			break;
		}
		case(2): {
			con.add_cargo(12);
			con.get_table_out();
			break;
		}
		
		default:
			cout << "There is no such command!" << endl << endl;
			break;
		}
	}
	return 0;
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
