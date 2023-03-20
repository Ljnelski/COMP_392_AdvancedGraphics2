#pragma once
#include <string>

namespace Week04
{
	class Date
	{
	private:
		static int ID;
		int year_;
		int month_;
		int day_;
		std::string id_;

	public:
		Date(int year = 2023, int month = 1, int day = 1);
		Date(const Date& other);
		~Date();
		Date operator+(const Date& rhs);
		Date operator+(const int rhs);
		friend std::ostream& operator<<(std::ostream& os, const Date& rhs);

	};
}