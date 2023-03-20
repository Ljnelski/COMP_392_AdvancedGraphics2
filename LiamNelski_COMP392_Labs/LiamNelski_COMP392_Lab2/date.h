#pragma once
#include <ostream>

namespace Week01
{
	class Date
	{
		int year_;
		int month_;
		int day_;

		void Normalize();

	public:
		Date(int, int = 1, int = 1);
		~Date();
		Date operator+(const Date&);
		Date operator+(const int);
		friend std::ostream& operator <<(std::ostream&, const Date&);
	};
}