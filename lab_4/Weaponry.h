#pragma once

#include <string>
enum Pos {
	Stern = 1,
	Bow = 2,
	Left = 3,
	Right = 4

};
struct Weaponry
{
	std::string name;
	double caliber;
	int range;
	Pos position; //1 - �����, 2 - ���, 3-����� ����, 4-������ ����
	int ammo;
};
