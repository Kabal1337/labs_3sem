#pragma once
#include <iostream>
#include <ostream>
#define _CRTDBG_MAP_ALLOC


class Sequence {
public:
	Sequence(); //������ ����������� ��� ������������� ����������� � �������� ����������� ������ �� ��������� (������ ����� = 0)
	Sequence(int length, const int* arr); //�������� ����������� ������ � �������������� �������� � ���������� ��������� �����-�������������;
	Sequence(int el); //c������� ����������� ������ � �������������� ������������ ��������� �������������-�����;
	
	int find_el_count(int num) const; //����������� ������� ��������� ���������� �������� � ������������������
	int uniq() const;//����������� ���������� ����� � ������������������ (�� ����, ������� ������ ��������� �������� � ������������������);
	void set_arr(int index, int num);  //�������� ����� ������� �� �������
	void see_seq(std::ostream& out) const; //������� ������������������
	Sequence unite(const Sequence* seq) const; //����������� ���� ������������������� � ����(� ������� �������������� ��������� �������� + ) � ���������� ����������� ����� ������ � ����������� ��������
	int get_el(int index) const;//�������� ������� ������������������ �� ��� �������
	int get_length() const;//�������� ����� ������� ������
	void add_el(int num); //�������� ���� ������� � ������������������
	void see_seq_up_or_down(int* array, int len, int what) const; //��������� ������ ������������� �� ��������(what=1) ��� �����������(what=2) ������������������ ������ �� ����� ��� ���������;

	int* get_seq(); //�������� ������ ������
	void input(std::istream& s);
	friend Sequence&operator+=(Sequence& seq1, Sequence& seq2);
	friend std::ostream& operator << (std::ostream& s, const Sequence& seq);
	friend std::istream& operator >> (std::istream& s, Sequence& seq);
	friend Sequence operator + (const Sequence& seq1, const Sequence& seq2);
	friend void operator += (Sequence& seq, int i);
	int operator () (int num);
private:
	int size = 100;
	int length;
	int arr[100];
	
};