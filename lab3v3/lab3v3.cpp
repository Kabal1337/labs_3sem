// lab3v3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Reads.h"
#include "Sequence.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/*
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	
	Sequence seq(10, arr);
	delete[] arr;
	*/
	//float  r;
	int com_num = 0;
	int num, index, temp;
	Sequence seq1;
	Sequence seq2;
	Sequence* seq3 = new Sequence;
	Sequence seq_one(3);
	cin >> seq1;
	cin >> seq2;
	cout << seq_one.get_el(0);
	//seq3.input();
	int* arr;
	while (com_num != 8)
	{

		cout << "1.Unite seq" << endl;
		cout << "2.See sequence" << endl;
		cout << "3.Count groups" << endl;
		cout << "4.Count element repit" << endl;
		cout << "5.Add element" << endl;
		cout << "6.See seq down" << endl;
		cout << "8. Exit" << endl;
		cout << "Command number: ";

		com_num = read_r();

		switch (com_num)
		{
		case 1:
			(*seq3 += seq1)+=seq2;
			break;
		case 2:
			cout << *seq3;
			break;
		case 3:
			
			cout << seq3->uniq() << endl;
			break;
		case 4:

			num = read_r();
			temp = seq1(num);
			cout << temp << endl;
			break;
		case 5:
			num = read_r();
			seq3+=num;
			break;
		case 6:

			arr = new int[10];
			try {
				seq1.see_seq_up_or_down(arr, 10, 1);
			}
			catch (const char* a) {
				cout << a;
			}
			for (int i = 0; i < 3; i++)
			{
				cout << arr[i] << ' ';
			}
			cout << endl;
			delete[] arr;
			break;
		case 7:
			index = read_r();
			cout << seq1.get_el(index);
			break;

		case 8:
			//_CrtDumpMemoryLeaks();
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
