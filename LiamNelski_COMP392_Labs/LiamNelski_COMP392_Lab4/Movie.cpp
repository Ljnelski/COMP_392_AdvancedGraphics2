#include "Movie.hpp"
#include <iostream>

namespace lab4
{

	Movie::Movie(std::string name, int year, int length)
		: title_{ name }, year_{ year }, cast_(), length_{ length }
	{
		SetGenre(GenreEnum::Unrated);
	}

	void Movie::AddActor(const std::string actor)
	{
		cast_.push_back(actor);
	}

	bool Movie::HasActor(const std::string actor)
	{
		return std::find(cast_.begin(), cast_.end(), actor) != cast_.end();
	}

	void Movie::SetGenre(const GenreEnum genre)
	{
		genre_enum = genre;
	}


	std::ostream& operator<<(std::ostream& os, const GenreEnum& genreEnum)
	{
		const char* genres[10] = { "Unrated", "Action", "Adventure", "Animation", "Comedy", "Documentary", "Horror", "Fantasy" , "Musical", "Romance" };

		os << genres[static_cast<int> (genreEnum)];
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		// Append Actors to a single string
		std::string actors = "";

		size_t size = movie.cast_.size();
		for (std::vector<std::string>::size_type i = 0; i != size; i++)
		{
			actors += movie.cast_[i];
			actors += (i == size - 1) ? "." : ", ";
		}
		os << movie.title_ << " (" << movie.year_ << ") " << movie.length_ << "min " << movie.genre_enum << ": " << actors << " $";

		return os;
	}

}
