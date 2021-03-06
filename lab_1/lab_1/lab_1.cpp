﻿// lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
class Mat_El {
public:
    int i;
    int j;
    int name;
    Mat_El* next;
    Mat_El() {
        next = NULL;
    }
};
class Matrix
{
public:
    int size;
    Mat_El** arr;

    Matrix(int size);

    
    void add(int name, int i, int j);
    int search(int i, int j, int n, int m);
    void mx_out(int n, int m);
    void mx_new(int m, int n);
    void del(int it, int jt);
};

int hash(int size, int i, int j);
int read(int* var);
int find_sum(int a);
int main()
{
    int i, j, n, m, temp;

    cout << "n: ";
    read(&n);
    cout << endl << "m: ";
    read(&m);
    cout << endl;
   
    Matrix mx(n);
    while (1) {
        cout << "i: ";
        read(&i);
        cout << endl;
       
        while (!cin.good() || i > n-1)
        {
            cout << endl << "Invalid input, try again" << endl;
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cin >> i;
        }
        if (i == -1) break;
        cout << "j: ";
        read(&j);
        cout << endl;
       
        while (!cin.good() || j > m-1)
        {
            cout << endl << "Invalid input, try again" << endl;
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cin >> j;
        }
        if (j == -1) break;
        cout << "name: ";
        cin >> temp;
        cout << endl;
        if (temp != 0)
        {
            mx.add(temp, i, j);
        }
        
    }
        
    
    
    cout << endl << "Original matrix";
    mx.mx_out(n, m);
    Matrix mx1(n);
    for (int i = 0; i < n; i++)
    {
       
        
            for (int j = 0; j < m; j++)
            {   
              
            
                mx1.add(mx.search(i, j, n, m), i, j);
            }

    }
    mx1.mx_new(m, n);
    mx1.mx_out(n, m);

    
    
    for (int i = 0; i < mx.size; i++)
    {
        delete mx.arr[i];
    }
    delete[] mx.arr;

   
    return 0;
}



int hash(int size, int i, int j)
{
	return (i + j) % size;


}
Matrix::Matrix(int size)
{
    this->size = size;
    arr = new Mat_El * [size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = NULL;
    }
}
void Matrix::add(int name, int i, int j)
{
    Mat_El* cur_ptr = arr[hash(size, i, j)];

    if (cur_ptr == NULL)
    {
        arr[hash(size, i, j)] = new Mat_El;
        cur_ptr = arr[hash(size, i, j)];
    }
    else if (cur_ptr != NULL)
    {
        while (cur_ptr->next != NULL)
        {
            cur_ptr = cur_ptr->next;
        }
        cur_ptr->next = new Mat_El;
        cur_ptr = cur_ptr->next;
    }

    cur_ptr->i = i;
    cur_ptr->j = j;
    cur_ptr->name = name;
    cur_ptr->next = NULL;
}
int Matrix::search(int i, int j, int n, int m)
{
    if ((i > n - 1) || (j > m -1)) {
        cout << "invalid i or j";
        return 0;
    }

    Mat_El* cur_ptr = arr[hash(size, i, j)];

    if (cur_ptr == NULL) return 0;

    while (cur_ptr->next != NULL)
    {
        if (cur_ptr->i == i && cur_ptr->j == j)
        {
            return cur_ptr->name;
        }
        cur_ptr = cur_ptr->next;
    }

    if (cur_ptr->i == i && cur_ptr->j == j)
    {
        return cur_ptr->name;
    }

    return 0;
}
int read(int* var)
{
    int temp;
    cin >> temp;

    while (!cin.good() || temp < -1)
    {
        cout << endl << "Invalid input, try again" << endl;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> temp;
    }

    *var = temp;
    return temp;
}
void Matrix::mx_out(int n, int m)
{
    int temp;

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp = search(i, j, n, m);
            if (temp != 0)
            {
                cout << temp << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
void Matrix::mx_new(int m, int n) {
    for (int i = 0; i < size; i++)
    {
        
        int k = search(i, m-1, n, m);
        int p = find_sum(k);
        for (int j = 0; j < m; j++)
        {   
            int num = hash(size, i, j);
            Mat_El* cur_ptr = arr[num];
            
            if (cur_ptr != NULL) {
                while (1) {
                    if ((cur_ptr->i == i) && (cur_ptr->j == j)) break;
                    cur_ptr = cur_ptr->next;
                }
                int q = find_sum(cur_ptr->name);
                if (q != p)
                    del(i, j);
                    
            }

            

        }
    }
}

void Matrix::del(int i, int j)
{
    Mat_El* cur_ptr = arr[hash(size, i, j)];
    Mat_El* prev_ptr = cur_ptr;

    if (cur_ptr == NULL)
    {
       
        return;
    }

    if (cur_ptr->i == i && cur_ptr->j == j)
    {
        arr[hash(size, i, j)] = cur_ptr->next;
        delete(cur_ptr);
        return;
    }

    while (cur_ptr->next != NULL)
    {
        prev_ptr = cur_ptr;
        cur_ptr = cur_ptr->next;

        if (cur_ptr->i == i && cur_ptr->j == j)
        {
            prev_ptr->next = cur_ptr->next;
            delete(cur_ptr);
            return;
        }
    }
    if (cur_ptr->i == i && cur_ptr->j == j)
    {
        prev_ptr->next = cur_ptr->next;
        delete(cur_ptr);
        return;
    }

}

int find_sum(int a) {
    int k = a;
    int count = 0;
    while (1) {
        
        int m = k % 10;
        k /= 10;
        count += m;
        if (k / 10 == 0) break;
        
    }
    count += k;
    return count;
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
