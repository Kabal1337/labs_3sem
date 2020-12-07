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
	
	this->length = length;
	this->arr = new int[length];
	if(arr!=nullptr)
	for (int i = 0; i < length; i++) {

		this->arr[i] = arr[i];
	}
}


void Sequence::see_seq(std::ostream& out) const
{

	for (int i = 0; i < length; i++)
	{
		out << this->arr[i] << ' ';

	}
	out << endl;
}
Sequence* Sequence::unite(const Sequence* seq) const {

	Sequence* seq_temp = new Sequence(length + seq->length, nullptr);
	for (int i = 0; i < length; i++)
	{
		seq_temp->arr[i] = arr[i];
	}
	for (int i = length; i < length + seq->length; i++)
	{
		seq_temp->arr[i] = seq->arr[i - length];
	}

	//cout << *seq_temp;

	return seq_temp;

}
int Sequence::get_el(int index) const {
	if (index >= length) throw "invalid index";
	return(arr[index]);
}
int* Sequence::get_seq() const {

	return(this->arr);
}
int Sequence::get_length() const
{
	return length;
}

void Sequence::add_el(int num)
{
	length++;
	int* arr_temp = new int[length];
	for (int i = 0; i < length-1; i++)
	{
		arr_temp[i] = arr[i];
	}
	delete arr;
	arr_temp[length - 1] = num;
	arr = arr_temp;
}


void Sequence::see_seq_up_or_down(int* array, int len, int what) const
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
		case 1:
			if (arr[i] > arr[i + 1]) {
				if (temp < 3) {
					temp = 0;
				}
				else {
					break;
				}
			}
			break;
		case 2:
			if (arr[i] < arr[i + 1]) {
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
	while (!std::cin.good() || length > SIZE)
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
	seq.input(s);
	return s;
}

Sequence* operator + (Sequence& seq1, Sequence& seq2)
{
	return(seq1.unite(&seq2));
}

void operator +=(Sequence& seq, int i)
{
	seq.add_el(i);
	return;
}

//Sequence* operator+=(Sequence& seq1, Sequence& seq2) {

	//seq1 = *seq1.unite(&seq2);
	//return(seq1);
//}

