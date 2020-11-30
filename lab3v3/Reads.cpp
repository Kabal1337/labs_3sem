#include "Reads.h"
#include "Sequence.h"
#include <iostream>

#include <math.h>
#include <cmath>
int read_r()
{
	int temp;
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

int read_length()
{
	int temp;
	std::cin >> temp;

	while (!std::cin.good() || temp > SIZE)
	{
		std::cout << std::endl << "Invalid input, try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> temp;
	}

	return temp;

}
