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

Sequence::Sequence(int length, int* arr) {
	this->length = length;
	for (int i = 0; i < length; i++) {
		
		set_arr(i, arr[i]);
	}
}
void Sequence::set_arr(int index, int num) {
	this->arr[index] = num;
	
}

void Sequence::see_seq()
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';

	}
	cout << endl;
}
Sequence Sequence::unite(Sequence seq) {
	
	Sequence seq_temp(length, arr);
	
	int j = 0;
	int i = length;
	while (j < seq.get_length()) {
		seq_temp.set_arr(i, seq.get_seq(j));
		j++;
		i++;
	}
	seq_temp.length += seq.get_length();
	return seq_temp;

}
int Sequence::get_seq(int index) {
	
	return(arr[index]);
}

int Sequence::get_length()
{
	return length;
}

void Sequence::add_el(int num)
{
	length++;
	arr[length - 1] = num;
}

void Sequence::see_seq_up()
{
	
	for (int i = 0; i < length; i++)
	{
		cout << arr[i]<<' ';
		if (arr[i] > arr[i + 1]) break;
	}
	cout << endl;
}
void Sequence::see_seq_down()
{

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
		if (arr[i] < arr[i + 1]) break;
	}
	cout << endl;
}
int Sequence::uniq() {

	std::set <int> st;
	for (int i = 0; i < length; i++)
	{
		st.insert(arr[i]);
		
	}
	return(st.size());

}
int Sequence::find_el(int num){
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
