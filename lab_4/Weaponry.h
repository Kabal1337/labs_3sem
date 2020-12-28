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
	Pos position; //1 - корма, 2 - нос, 3-левый борт, 4-правый борт
	int ammo;
};
