#include "Sequence.h"
#include <iostream>
#include <set>
using std::cin;
using std::cout;
using std::endl;


Sequence::Sequence()
{
	length = 0;
	arr = nullptr;
}
Sequence::~Sequence()
{
		delete[] arr;
}
Sequence::Sequence(int el) {
	length = 1;
	arr = new int[length];
	arr[0] = el;
	
}
Sequence::Sequence(int length, const int* arr) {
	if (length < 0) throw "invalid length";
	this->length = length;
	this->arr = new int[length];
	if(arr!=nullptr)
	for (int i = 0; i < length; i++) {

		this->arr[i] = arr[i];
	}
}
Sequence::Sequence(const Sequence& seq)
{
	this->length = seq.get_length();
	this->arr = new int[seq.length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = seq.get_el(i);
	}
	
}

Sequence::Sequence(Sequence&& seq)
{
	this->length = seq.get_length();
	this->arr = seq.arr;
	
	seq.arr = nullptr;
	seq.length = 0;
}

void Sequence::see_seq(std::ostream& out) const
{
	
	for (int i = 0; i < length; i++)
	{
		out << this->arr[i] << ' ';

	}
	out << endl;
}
Sequence& Sequence::unite(const Sequence& seq) const {

	Sequence* seq_temp = new Sequence(length + seq.length, nullptr);
	for (int i = 0; i < length; i++)
	{
		seq_temp->arr[i] = arr[i];
	}
	for (int i = length; i < length + seq.length; i++)
	{
		seq_temp->arr[i] = seq.arr[i - length];
	}

	//cout << *seq_temp;

	return *seq_temp;

}
int Sequence::get_el(int index) const {
	if (index >= length) throw "invalid index";
	return(arr[index]);
}

int Sequence::get_length() const
{
	return length;
}

void Sequence::add_el(int num)
{
	
	int* arr_temp = new int[length+1];
	length++;
	for (int i = 0; i < length-1; i++)
	{
		arr_temp[i] = arr[i];
	}
	delete arr;
	arr_temp[length - 1] = num;
	arr = arr_temp;
}


void Sequence::see_seq_up_or_down(int* array, int len, what what) const
{
	if (len < 3) {
		throw "invalid array's length";
	}


	int* arr_temp = new int[len];
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		arr_temp[temp] = arr[i];

		temp++;
		switch (what) {
		case down:
			if (arr[i] < arr[i + 1]) {
				if (temp < 3) {
					temp = 0;
				}
				else {
					break;
				}
			}
			break;
		case up:
			if (arr[i] > arr[i + 1]) {
				if (temp < 3) {
					temp = 0;
				}
				else {
					break;
				}
			}
			break;
		default: throw "invalid command";
			break;
		}

	}
	if (temp < 3) {
		throw "too few";
	}

	if (len > temp) {
		for (int i = 0; i < temp; i++)
		{
			array[i] = arr_temp[i];
		}
	}
	else {
		for (int i = 0; i < len; i++)
		{
			array[i] = arr_temp[i];
		}
	}
	delete[] arr_temp;

}

int Sequence::uniq() const {

	std::set <int> st;
	for (int i = 0; i < length; i++)
	{
		st.insert(arr[i]);

	}
	return(st.size());

}
int Sequence::find_el_count(int num) const {
	int temp = 1;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == num) {
			for (int j = 0; j < length; j++)
			{
				if ((arr[i] == arr[j]) && (i != j)) {
					temp++;

				}
			}
			return(temp);
		}
	}
	throw "Invalid input";
	return(0);
}
void Sequence::input(std::istream& s) {
	cout << "Length: ";


	s >> length;
	cout << endl;
	while (!std::cin.good())
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		s.clear();
		s.ignore(std::cin.rdbuf()->in_avail());
		s >> length;
	}
	int* arr_temp = new int[length];
	for (int i = 0; i < length; i++) {
		s >>arr_temp[i];
		while (!std::cin.good())
		{
			cout << std::endl << "Invalid input, try again" << std::endl;
			s.clear();
			s.ignore(std::cin.rdbuf()->in_avail());
			s >> arr_temp[i];
		}

	}
	delete[] arr;
	arr = arr_temp;
}

Sequence& Sequence::operator=(Sequence&& seq)
{
	if (&seq == this) return *this;
	this->length = seq.get_length();
	this->arr = new int[seq.length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = seq.get_el(i);
	}
	
	return *this;
}

Sequence& Sequence::operator=(const Sequence& seq) //a=b 
{
	if (&seq == this) return *this;
	this->length = seq.get_length();
	this->arr = new int[seq.length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = seq.get_el(i);
	}
	return *this;
}
int Sequence::operator()(int num)
{
	return (find_el_count(num));
}




std::ostream& operator <<(std::ostream& s, const Sequence& seq)
{
	seq.see_seq(s);
	return s;
}

std::istream& operator >> (std::istream& s, Sequence& seq) {
	cout << "Length: ";


	s >> seq.length;
	cout << endl;
	if (!std::cin.good())
	{
		throw "Invalid input";
		
		
	}
	int* arr_temp = new int[seq.length];
	for (int i = 0; i < seq.length; i++) {
		s >> arr_temp[i];
		if (!std::cin.good())
		{
			throw "Invalid input";
			
		}

	}
	delete[] seq.arr;
	seq.arr = arr_temp;
}

Sequence& operator + (const Sequence& seq1, const Sequence& seq2)
{
	return(seq1.unite(seq2));
}

Sequence& Sequence::operator +=(const int i)
{
	//seq.add_el(i);
	this->add_el(i);
	return(*this);
}

Sequence& Sequence::operator+=(const Sequence& seq1) {

	*this = this->unite(seq1);
	return(*this);
}

