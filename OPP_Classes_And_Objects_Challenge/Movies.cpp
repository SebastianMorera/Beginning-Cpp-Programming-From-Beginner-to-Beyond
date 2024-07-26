#include "Movies.h"
#include <iostream>

Movies::Movies() = default;
Movies::~Movies() = default;


bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    for(const auto &movie: movies)
    {
        if(movie.get_name() == name)
            return false;
    }

    Movie newMovie {name, rating, watched};
    movies.push_back(newMovie);
    return true;
}

bool Movies::increment_watched(std::string name)
{
    for(auto &movie: movies)
    {
        if(movie.get_name() == name)
        {
            movie.increment_watched();
            return true;
        }
    }

    return false;
}

void Movies::display() const
{
    if(movies.empty())
        std::cout << "Sorry, no movies to display \n" << std::endl;
    else {
        std::cout << "\n===================================" << std::endl;
        for (const auto &movie: movies)
            movie.display();
        std::cout << "\n===================================" << std::endl;
    }   
}
