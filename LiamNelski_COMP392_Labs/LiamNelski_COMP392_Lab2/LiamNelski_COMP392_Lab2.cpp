// LiamNelski_COMP123_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "date.h"

int main()
{
	std::cout << "\ncreating an anonymous object - 1\n";
	std::cout << Week01::Date(2019) << '\n';

	std::cout << "\ncreating a named object - 2\n";
	Week01::Date d1(2020, 3, 28);
	std::cout << d1 << '\n';

	std::cout << "\ncreating another named object - 3\n";
	Week01::Date d2(2, 10, 14);
	std::cout << d2 << '\n';

	std::cout << "\ncreating another named object - 4\n";
	Week01::Date d3 = d1 + d2;
	std::cout << d1 << " + " << d2 << " = " << d3 << '\n';
	int days = 84;

	//setting a new object to d3
	std::cout << "\nsetting a new object to an existing variable\n";
	d3 = d2 + days;
	std::cout << d2 << " + " << days << " = " << d3 << '\n';

	std::cout << d1 << '\n';
	std::cout << d2 << '\n';
	std::cout << d3 << '\n';

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu