#pragma once
#include <string>;
struct Captain
{
	Captain()
	{
		old = 0;
		name = "null";
		surname = "null";
		patronymic = "null";
		experience = 0;
	}
	int old;
	std::string name;
	std::string surname;
	std::string patronymic;
	int experience;
};