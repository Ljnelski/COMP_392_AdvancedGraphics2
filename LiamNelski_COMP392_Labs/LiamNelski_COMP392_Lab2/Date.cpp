#include "date.h"
#include <iostream>

namespace Week01
{
	void Date::Normalize()
	{
		if (day_ < 1) day_ = 1;
		if (month_ < 1) month_ = 1;

		if (day_ > 30)
		{
			month_ = month_ + (day_ - 1) / 30;
			day_ = (day_ - 1) % 30 + 1;
		}
		if (month_ > 12)
		{
			year_ = year_ + (month_ - 1) / 12;
			month_ = (month_ - 1) % 12 + 1;
		}
	}

	Date::Date(int year, int month, int day)
	{
		std::cout << "constructor\n";
		year_ = year;
		month_ = month;
		day_ = day;
		Normalize();
	}

	Date::~Date()
	{
		std::cout << "destructor\n";
	}

	Date Date::operator+(const Date& rhs)
	{
		return Date{ year_ + rhs.year_, month_ + rhs.month_, +day_ + rhs.day_ };
	}

	Date Date::operator+(const int rhs)
	{
		return Date(year_, month_, day_ + rhs);
	}

	std::ostream& operator <<(std::ostream& os, const Date& date)
	{
		os << "<" << date.year_ << "-" << date.month_ << "-" << date.day_ << ">";
		return os;
	}
}