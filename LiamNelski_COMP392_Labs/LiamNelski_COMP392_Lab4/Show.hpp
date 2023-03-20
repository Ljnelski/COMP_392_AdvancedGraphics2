#pragma once
#include "DayEnum.hpp"
#include "Time.hpp"
#include "Movie.hpp"

#include <ostream>

namespace lab4
{
	class Show
	{
	public:
		double price_;
		DayEnum dayEnum_;
		Movie movie_;
		Time time_;

		Show(Movie movie, Time time, DayEnum dayEnum, double price);

		Time GetTime();
		DayEnum GetDay();
		GenreEnum GetGenre();
		bool HasActor(const std::string& actor);

		friend std::ostream& operator<<(std::ostream& os, const Show& show);
		friend std::ostream& operator<<(std::ostream& os, const DayEnum& dayEnum);
	};
}