#pragma once
#define _CRTDBG_MAP_ALLOC
#define SIZE 100
class Sequence {
public:
	Sequence();
	Sequence(int length, int* arr);
	
	//Sequence(int length);
	int find_el(int num);
	int uniq();
	void set_arr(int index, int num);
	void see_seq();
	Sequence unite(Sequence seq);
	int get_seq(int index);
	int get_length();
	void add_el(int num);
	void see_seq_up();
	void see_seq_down();
private:
	int length;
	int arr[SIZE];
	
};