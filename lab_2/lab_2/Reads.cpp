#pragma once
#include "Reads.h"
#include <iostream>
#define M_PI 3.14
#include <math.h>
#include <cmath>
#include "Astroid.h"
float read_r()
{
	float temp;
	std::cin >> temp;

	while (!std::cin.good())
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> temp;
	}

	return temp;
}
float read_angle()
{
	float temp;
	std::cin >> temp;

	while (!std::cin.good() || temp<0 || temp > M_PI/2 )
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> temp;
	}

	return temp;
}
