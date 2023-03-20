#include <iostream>
#include "lab2_date.hpp"


namespace Week04
{
	int Date::ID = 100;

	Date::Date(int year, int month, int day) 
		: year_{ year }, month_{ month }, day_{day}
	{
		id_ = std::to_string(Date::ID++);
		std::cout << "++ constructor id: " << id_ << "\n";
	}

	Date::Date(const Date& other):
		year_{other.year_}, month_{other.month_}, day_{other.day_}
	{
		id_ = std::to_string(Date::ID++);
		std::cout << "++ copy constructor id: " << id_ << "\n";
	}

	Date::~Date()
	{
		std::cout << "++ destructior id: " << id_ << "\n";
	}

	Date Date::operator+(const Date& rhs)
	{
		Date temp(year_ + rhs.year_, month_ + rhs.month_, day_ + rhs.day_);
		return temp;
	}
	
	Date Date::operator+(const int rhs)
	{
		Date temp(year_, month_, day_ + rhs);
		return temp;
	}
	
	std::ostream& operator<<(std::ostream& os, const Date& rhs)
	{
		return os << "<" << rhs.day_ << "-" << rhs.month_ << "-" << rhs.year_ << ">\n";
		
	}
}

