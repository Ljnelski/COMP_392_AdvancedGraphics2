#pragma once

#include "Account.hpp"
#include <iostream>

namespace Week03
{
	int Account::LAST_NUMBER = 1000;

	Account::Account(double balance)
	{
		// > Assign Account Number
		account_number = std::to_string(LAST_NUMBER);
		LAST_NUMBER++;

		balance_ = balance;

		std::cout << "++ Account constructor: " << account_number << "\n";
	}

	Account::~Account()
	{
		std::cout << "-- Account destructor: " << account_number << "\n";
	}

	double Account::get_balance()
	{
		return balance_;
	}

	void Account::print_info()
	{
		std::cout << account_number << " balance: " << balance_ << "\n";
	}
}