// TestLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "pch.h"
using std::cout;
#include <iostream>
#include <cmath>
#define NUM_OF_TESTS 10
using std::endl;
#define M_PI 3.14
int main()
{	
	cout << "Testing..."<<endl;
	for (float i = 0; i < NUM_OF_TESTS; i++)
	{	
		cout << "r: " <<  i<< endl;
		Astroid ast(i);
		
		cout << "Testing get_r()" << endl;
		if (ast.get_r() == i) {
			cout << "Success" << endl;
		}
		else {
			cout << "error" << endl;
		}

		cout << "Testing get_length_0_t()" << endl;
		for (float j = 0; j < M_PI/2; j+=0.1)
		{
			cout << "r: " << i << endl;
			cout << "t: " << j << endl;
			float temp = 1.5 * i * pow(sin(j), 2);
			if (ast.get_length_0_t(j) == temp)
			{	
				cout << "Success" << endl;
			}
			else {
				cout << "error" << endl;
			}
			cout << "Testing get_radius()" << endl;
			cout << "r: " << i << endl;
			cout << "t: " << j << endl;
			temp = 1.5 * i * sin(2 * j);
			if (ast.get_radius(j) == temp)
			{
				cout << "Success" << endl;
			}
			else {
				cout << "error" << endl;
			}
			cout << "Testing :get_x_from_t()" << endl;
			cout << "r: " << i << endl;
			cout << "t: " << j << endl;
			temp = i * pow(cos(j), 3);
			if (ast.get_x_from_t(j) == temp)
			{
				cout << "Success" << endl;
			}
			else {
				cout << "error" << endl;
			}
			cout << "Testing :get_y_from_t()" << endl;
			cout << "r: " << i << endl;
			cout << "t: " << j << endl;
			temp = i * pow(sin(j), 3);
			if (ast.get_y_from_t(j) == temp)
			{
				cout << "Success" << endl;
			}
			else {
				cout << "error" << endl;
			}
		
		
		}
		
		
		cout << "Testing get_s()" << endl;
		
		cout << "r: " << i << endl;
			float m = pow(i, 2);
			float s = 0.375 * M_PI * m;
			if (ast.get_s() == s)
			{
				cout << "Success" << endl;
			}
			else {
				cout << "error" << endl;
			}
		cout << "Testing :get_x0" << endl;
		cout << "r: " << i << endl;
		float temp = (pow(i, 0.67));
		if (ast.get_x0() == temp) {
			cout << "Success" << endl;
		}
		else {
			cout << "error" << endl;
		}
		cout << "Testing :get_y_from_x()" << endl;
		cout << "r: " << i << endl;
		for (int x = -ast.get_x0(); x < ast.get_x0(); x += 1) {
			cout << "x: " << x << endl;
			float temp = pow(i, 0.67) - pow(abs(x), 0.67);
			float y = pow(abs(temp), 1.5);
			if (ast.get_y_from_x(x)==y) {
				cout << "Success" << endl;
			}
			else {
				cout << "error" << endl;
			}
		}
	}
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
