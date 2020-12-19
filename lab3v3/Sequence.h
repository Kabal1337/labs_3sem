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
	Sequence(const Sequence& seq);
	Sequence(Sequence&& seq);
	int find_el_count(int num) const; //определение частоты по€влени€ некоторого элемента в последовательности
	int uniq() const;//определение количества групп в последовательности (то есть, сколько разных элементов включено в последовательность);
	
	void see_seq(std::ostream& out) const; //увидеть последовательность
	Sequence* unite(const Sequence& seq) const; //объединение двух последовательностей в одну(с помощью перегруженного оператора сложени€ + ) в результате формируетс€ новый вектор с сохранением исходных
	int get_el(int index) const;//получить элемент последовательности по его индексу
	int get_length() const;//получить длину массива класса
	void add_el(int num); //добавить один элемент в последовательность
	
	void see_seq_up_or_down(int* array, int len, int what) const; //выделение первой упор€доченной по убыванию(what=1) или возрастанию(what=2) последовательности длиной не менее трЄх элементов;

	int* get_seq() const; //передает массив класса
	void input(std::istream& s);
	friend std::ostream& operator << (std::ostream& s, const Sequence& seq);
	friend std::istream& operator >> (std::istream& s, Sequence& seq);
	friend Sequence operator + (const Sequence& seq1, const Sequence& seq2);
	friend Sequence& operator+=(Sequence& seq1, const Sequence& seq2);
	friend void operator += (Sequence& seq, int i);
	Sequence& operator=(Sequence&& seq2);
	Sequence& operator=(const Sequence& seq);
	int operator () (int num);
private:
	int length;
	int *arr;

};
