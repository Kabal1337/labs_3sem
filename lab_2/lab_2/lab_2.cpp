#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Reads.h"
#include "Astroid.h"
#define M_PI 3.14
int main()
{
	float length, r, x;
	int com_num=0;
	r = read_r();
	
	Astroid astroid(r);
	float t;
	while (com_num != 8)
	{
		cout << "1. Get length 0-t" << endl;
		cout << "2. Get length" << endl;
		cout << "3. Find radius of curvature (t)" << endl;
		cout << "4. Find area" << endl;
		cout << "5. Find x(t) and y(t)" << endl;
		cout << "6. Find y(x)" << endl;
		cout << "7.Set r";
		cout << "8. Exit" << endl;
		cout << "Command number: ";

		com_num = read_r();

		switch (com_num)
		{
		case 1:
			t = read_r();
			try {
				length = astroid.get_length_0_t(t);

				cout << length << endl;
			}
			catch (const char* str) {
				std::cerr << str << endl;

			}
			 break;
		case 2:
			
			cout << 6*r << endl;
			break;
		case 3:
			t = read_r();
			try {
				cout << astroid.get_radius(t) << endl;
			}
			catch (const char* str) {
				std::cerr << str << endl;

			}
			break;
		case 4:
			cout << astroid.get_s() << endl;
			break;
		case 5:
			
			t=read_r();
			try {
				cout << "x: " << astroid.get_x_from_t(t) << endl;
				cout << "y: " << astroid.get_y_from_t(t) << endl;
			}
			catch (const char* str) {
				std::cerr << str << endl;
				
			}
			break;

		case 6:
			x = read_r();
			

			

			try
			{
				cout << "y=+-" << abs(astroid.get_y_from_x(x));
			}
			catch (const char* str)
			{
				std::cerr << str << endl;;
			}


			break;
		
		case 7:
			t = read_r();
			astroid.set_r(t);
			break;
		case 8:

			return 0;
			break;
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
