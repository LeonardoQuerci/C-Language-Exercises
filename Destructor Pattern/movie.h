#ifndef MOVIE_H
#define MOVIE_H

// TODO: Define the Movie struct with:
// - char *title (dynamically allocated string)
// - int year
typedef struct {
    char *title;
    int year;
}Movie;

// TODO: Declare the constructor function
Movie* create_movie(const char *title, int year);

// TODO: Declare the destructor function
void free_movie(Movie *movie);

#endif
