#pragma once

#include <string>

namespace Week03
{
	class Account
	{
		static int LAST_NUMBER;
		std::string account_number;
		double balance_;

	public:
		Account(double balance);
		~Account();
		double get_balance();
		void print_info();
	};
}