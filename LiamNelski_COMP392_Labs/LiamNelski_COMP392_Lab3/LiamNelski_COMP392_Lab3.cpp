// LiamNelski_COMP392_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Account.hpp"
#include "Timer.hpp"

Week03::Account** sort_accounts(Week03::Account** accounts, int size)
{
	Timer timer;
	int swap_count = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (accounts[j]->get_balance() > accounts[j + 1]->get_balance())
			{
				std::swap(accounts[j], accounts[j + 1]);
				swap_count++;
			}
		}
	}
	std::cout << swap_count << " swaps.";
	return accounts;
}

void print_accounts(Week03::Account** accounts, int size)
{
	for (int i = 0; i < size; i++)
	{
		accounts[i]->print_info();
	}
}

Week03::Account** create_accounts(int size, int max_balance)
{
	// > Why two asterisk
	Week03::Account** accounts = new Week03::Account * [size];

	for (int i = 0; i < size; i++)
	{
		*(accounts + i) = new Week03::Account(rand() % max_balance);
	}

	std::cout << "Creating Accounts";
	return accounts;
}

void test_account()
{
	srand(301064116); //use your student number
	const int MAX_BALANCE = 100000;
	const int SIZE = 20; //change this number to investigate performance
	Week03::Account a1(rand() % MAX_BALANCE);
	Week03::Account a2(rand() % MAX_BALANCE);
	Week03::Account a3(rand() % MAX_BALANCE);
	Week03::Account a4(rand() % MAX_BALANCE);
	a1.print_info();
	a2.print_info();
	a3.print_info();
	a4.print_info();
	std::cout << "\nCreating the list of accounts:\n";
	Week03::Account** accounts = create_accounts(SIZE, MAX_BALANCE);
	std::cout << "\nPrinting the list of accounts:\n";
	print_accounts(accounts, SIZE);
	std::cout << "\nSorting the list of accounts:\n";
	sort_accounts(accounts, SIZE);
	std::cout << "\nPrinting the list of accounts:\n";
	print_accounts(accounts, SIZE);
	std::cout << "\nDeleting the accounts:\n";
	for (int i = 0; i < SIZE; i++)
	{
		delete(accounts[i]);
	}
}

int main()
{
    std::cout << "Hello World!\n";
    test_account();
}

