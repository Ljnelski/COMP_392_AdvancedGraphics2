#include "Show.hpp"
#include "Movie.hpp"
#include "Theatre.hpp"

#include <iostream>
#include <algorithm>

namespace lab4
{
	Theatre::Theatre(std::string name) : name_{ name }, shows_()
	{

	}

	void Theatre::AddShow(const Show show)
	{
		shows_.push_back(show);
	}

	void Theatre::PrintShows()
	{
		std::cout << "\n" << name_ << "\nAll Movie\n================\n";


		for (Show show : shows_)
		{
			std::cout << show << "\n";
		}
	}

	void Theatre::PrintShows(GenreEnum genre)
	{
		std::cout << "\n" << name_ << "\nAll genre Movie\n================\n";

		for (Show show : shows_)
		{
			if (show.GetGenre() == genre)
			{
				std::cout << show << "\n";
			}
		}

	}

	void Theatre::PrintShows(lab4::DayEnum day)
	{
		std::cout << "\n" << name_ << "\nAll " << "day " << "Movie\n================\n";

		for (Show show : shows_)
		{
			if (show.GetDay() == day)
			{
				std::cout << show << "\n";
			}
		}
	}

	void Theatre::PrintShows(Time time)
	{
		std::cout << "\n" << name_ << "\nAt " << time << " Movie\n================\n";
		for (Show show : shows_)
		{
			if (show.time_ == time)
			{
				std::cout << show << "\n";
			}
		}
	}

	void Theatre::PrintShows(std::string actor)
	{
		for (Show show : shows_)
		{
			if(show.HasActor(actor))
			std::cout << show << "\n";
		}
	}

	void Theatre::PrintShows(DayEnum day, Time time)
	{
		for (Show show : shows_)
		{
			if (show.GetDay() == day && show.time_ == time)
			{
				std::cout << show << "\n";
			}
		}
	}
}
