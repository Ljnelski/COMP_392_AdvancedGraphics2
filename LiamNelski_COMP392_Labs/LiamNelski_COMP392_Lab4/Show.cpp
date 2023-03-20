#include "Show.hpp"
#include "Time.hpp"

namespace lab4
{

	Show::Show(Movie movie, Time time, DayEnum dayEnum, double price)
		: movie_ {movie}, time_ {time}, dayEnum_ {dayEnum}, price_{price}
	{
		;
	}

	Time Show::GetTime()
	{
		return time_;
	}

	DayEnum Show::GetDay()
	{
		return dayEnum_;
	}

	GenreEnum Show::GetGenre()
	{
		return movie_.genre_enum;
	}

	bool Show::HasActor(const std::string& actor)
	{
		return movie_.HasActor(actor);
	}

	std::ostream& operator<<(std::ostream& os, const DayEnum& dayEnum)
	{
		const char* days[10] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		os << days[static_cast<int> (dayEnum)];

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Show& show)
	{
		os << show.dayEnum_ << " " << show.time_ << " " << show.movie_ << show.price_;
		return os;
	}	
}
