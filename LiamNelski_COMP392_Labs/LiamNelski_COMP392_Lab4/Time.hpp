#pragma once
#include <iostream>
#include <iomanip>

namespace lab4
{
	class Time
	{
	private:
		int hour_;
		int minutes_;
	public:
		Time(int hours = 0, int minutes = 0);
		friend bool operator==(const Time& lhs, const Time& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Time &time);
	};
}