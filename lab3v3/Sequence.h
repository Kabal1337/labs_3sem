#pragma once
#include <iostream>
#include <ostream>
#define _CRTDBG_MAP_ALLOC
#define SIZE 100

class Sequence {
public:
	Sequence(); //������ ����������� ��� ������������� ����������� � �������� ����������� ������ �� ��������� (������ ����� = 0)
	Sequence(int length, const int* arr); //�������� ����������� ������ � �������������� �������� � ���������� ��������� �����-�������������;
	Sequence(int el); //c������� ����������� ������ � �������������� ������������ ��������� �������������-�����;
	~Sequence();

	int find_el_count(int num) const; //����������� ������� ��������� ���������� �������� � ������������������
	int uniq() const;//����������� ���������� ����� � ������������������ (�� ����, ������� ������ ��������� �������� � ������������������);
	
	void see_seq(std::ostream& out) const; //������� ������������������
	Sequence* unite(Sequence* seq); //����������� ���� ������������������� � ����(� ������� �������������� ��������� �������� + ) � ���������� ����������� ����� ������ � ����������� ��������
	int get_el(int index) const;//�������� ������� ������������������ �� ��� �������
	int get_length() const;//�������� ����� ������� ������
	void add_el(int num); //�������� ���� ������� � ������������������
	void see_seq_up(int* array) const; //��������� ������ ������������� �� ����������� ������������������ ������ �� ����� ��� ���������;
	void see_seq_down(int* array) const;//��������� ������ ������������� �� �������� ������������������ ������ �� ����� ��� ���������
	int* get_seq() const; //�������� ������ ������
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
