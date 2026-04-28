#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

// TODO: Implement create_movie function
// - Allocate memory for the Movie struct
// - Allocate memory for the title string (don't forget null terminator)
// - Copy the title string
// - Set the year
// - Return the pointer to the new Movie
Movie* create_movie(const char *title, int year){
    Movie *m=malloc(sizeof(Movie));
    m->title=malloc(strlen(title)+1);
    m->year=year;
    strcpy(m->title,title);
    m->year=year;
    return m;
}
// TODO: Implement free_movie function
// - Add NULL check for safety
// - Free memory in REVERSE order of allocation:
//   1. First free the title string
//   2. Then free the struct itself
void free_movie(Movie *m){
    if (m==NULL)return;
    free(m->title);
    free(m);
}



