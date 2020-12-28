#include "Sequence.h"
#include <iostream>
#include <set>
using std::cin;
using std::cout;
using std::endl;


Sequence::Sequence()
{
	length = 0;

}
Sequence::Sequence(int el) {
	arr[0] = el;
	length = 1;
}
Sequence::Sequence(int length, const int* arr) {
	if ((length < 0) || (length > 100)) throw "invalid length";
		
		this->length = length;
		if(arr!=nullptr)
		for (int i = 0; i < length; i++) {

			set_arr(i, arr[i]);
		}
	
}
void Sequence::set_arr(int index, int num) {
	this->arr[index] = num;

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
	if ((this->length + seq.length) > 100) throw "too long seqs";
	

	Sequence* seq_temp = new Sequence(length + seq.length, nullptr);
	for (int i = 0; i < length; i++)
	{
		seq_temp->arr[i] = arr[i];
	}
	for (int i = length; i < length + seq.length; i++)
	{
		seq_temp->arr[i] = seq.arr[i - length];
	}
		return *seq_temp;
	
}
int Sequence::get_el(int index) const {
	if (index >= 100) throw "invalid index";
	
		return(arr[index]);
}

int Sequence::get_length() const
{
	return length;
}

void Sequence::add_el(int num)
{
	length++;
	arr[length - 1] = num;
}

void Sequence::see_seq_up_or_down(int* array, int len, what what) const
{
	if ((len < 3) || (len > 100)) {
		throw "invalid array's length";
	}
	

		int arr_temp[100];
		int temp = 0;
		for (int i = 0; i < length; i++)
		{
			arr_temp[temp] = arr[i];

			temp++;
			switch (what) {
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
	//cout << "Invalid input";
	return(0);
}
void Sequence::input(std::istream& s) {
	cout << "Length1: ";


	s >> length;
	cout << endl;
	while (!std::cin.good() || length > 100)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		s.clear();
		s.ignore(std::cin.rdbuf()->in_avail());
		s >> length;
	}

	for (int i = 0; i < length; i++) {
		s >> this->arr[i];
		while (!std::cin.good())
		{
			std::cout << std::endl << "Invalid input, try again" << std::endl;
			s.clear();
			s.ignore(std::cin.rdbuf()->in_avail());
			s >> this->arr[i];
		}

	}
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
	 int arr_temp[100];
	for (int i = 0; i < seq.length; i++) {
		s >> arr_temp[i];
		if (!std::cin.good())
		{
			throw "Invalid input";

		}

	}
	for (int i = 0; i < seq.length; i++)
	{
		seq.arr[i] = arr_temp[i];
	}
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

