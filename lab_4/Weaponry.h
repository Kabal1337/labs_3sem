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
	Weaponry() {
		name = "null";
		caliber = 0;
		range = 0;
		position = Stern;
		ammo = 0;
	}
	std::string name;
	unsigned caliber;
	unsigned range;
	Pos position; //1 - корма, 2 - нос, 3-левый борт, 4-правый борт
	unsigned ammo;
};
