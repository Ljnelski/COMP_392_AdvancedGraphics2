#pragma once
#include <vector>
#include <string>
#include "GenreEnum.hpp"


namespace lab4
{
	class Movie
	{
	private:
		int length_;
		int year_;
		std::string title_;
		std::vector<std::string> cast_;
		lab4::GenreEnum genre_enum;

	public:
		Movie(std::string name, int year, int length);

		void AddActor(const std::string actor);
		bool HasActor(const std::string actor);
		void SetGenre(const GenreEnum genre);

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
		friend std::ostream& operator<<(std::ostream& os, const GenreEnum& genreEnum);

		friend class Show;
	};
}