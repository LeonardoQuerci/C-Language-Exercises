#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

int main() {
    char title[100];
    int year;
    
    // Read input
    scanf("%[^\n]", title);
    scanf("%d", &year);
    
    // TODO: Create a movie using create_movie
    Movie *m=create_movie(title,year);
    // TODO: Print the movie information in format:
    // Movie: {title} ({year})
    printf("Movie: %s (%d)\n",m->title,m->year);
    // TODO: Free the movie using free_movie
    free_movie(m);
    // TODO: Print "Memory freed"
    printf("Memory freed");
    return 0;
}
