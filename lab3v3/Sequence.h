#pragma once
#include <iostream>
#include <ostream>
#define _CRTDBG_MAP_ALLOC
#define SIZE 100

class Sequence {
public:
	Sequence(); //пустой конструктор дл€ инициализации экземпл€ров и массивов экземпл€ров класса по умолчанию (делает длину = 0)
	Sequence(int length, const int* arr); //создание экземпл€ров класса с инициализацией размером и значени€ми элементов после-довательности;
	Sequence(int el); //cоздание экземпл€ров класса с инициализацией единственным элементом последователь-ности;
	~Sequence();

	int find_el_count(int num) const; //определение частоты по€влени€ некоторого элемента в последовательности
	int uniq() const;//определение количества групп в последовательности (то есть, сколько разных элементов включено в последовательность);
	
	void see_seq(std::ostream& out) const; //увидеть последовательность
	Sequence* unite(Sequence* seq); //объединение двух последовательностей в одну(с помощью перегруженного оператора сложени€ + ) в результате формируетс€ новый вектор с сохранением исходных
	int get_el(int index) const;//получить элемент последовательности по его индексу
	int get_length() const;//получить длину массива класса
	void add_el(int num); //добавить один элемент в последовательность
	void see_seq_up(int* array) const; //выделение первой упор€доченной по возрастанию последовательности длиной не менее трЄх элементов;
	void see_seq_down(int* array) const;//выделение первой упор€доченной по убыванию последовательности длиной не менее трЄх элементов
	int* get_seq() const; //передает массив класса
	void input();
	friend std::ostream& operator << (std::ostream& s, const Sequence& seq);
	friend std::istream& operator >> (std::istream& s, Sequence& seq);
	friend Sequence* operator + (Sequence& seq1, Sequence& seq2);
	friend void operator += (Sequence& seq, int i);
	int operator () (int num);
private:
	int length;
	int *arr;

};
