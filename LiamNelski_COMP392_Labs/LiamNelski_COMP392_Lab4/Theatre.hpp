#pragma once
#include <string>
#include <vector>
#include <iostream>


#include "Movie.hpp"
#include "Show.hpp"
namespace lab4
{
	class Theatre
	{
	private: 
		std::string name_;
		std::vector<Show> shows_;

	public: 
		Theatre(std::string name);

		void AddShow(const Show show);
		void PrintShows();
		void PrintShows(GenreEnum genre);
		void PrintShows(DayEnum day);
		void PrintShows(Time time);
		void PrintShows(std::string actor);
		void PrintShows(DayEnum day, Time time);
	};
}