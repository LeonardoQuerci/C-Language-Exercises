#include <stdlib.h>
#include "score.h"

// TODO: Define the actual struct Score with a single member: int points
struct Score{
    int points;
};
// TODO: Implement create_score
// Allocate memory for Score, set initial points, return pointer
Score* create_score(int x){
    Score *s= malloc(sizeof(Score));
    s->points=x;
    return s;
}
// TODO: Implement free_score
// Free the allocated memory
void free_score(Score *ptr){
    if(ptr==NULL)return;
    free(ptr);
}
// TODO: Implement score_get_points (getter)
// Return the points value from the Score struct
// Remember: parameter should be const Score *
int score_get_points(const Score *ptr){
    return ptr->points;
}
// TODO: Implement score_set_points (setter)
// Update the points value in the Score struct
void score_set_points(Score *ptr, int x){
    ptr->points=x;
}