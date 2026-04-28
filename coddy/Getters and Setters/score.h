// TODO: Add include guards using SCORE_H
#ifndef SCORE_H
#define SCORE_H
// TODO: Forward declare the Score struct (opaque pointer pattern)
// Hint: Use "typedef struct Score Score;"
typedef struct Score Score;
// TODO: Declare create_score function
// Takes an integer for initial points, returns Score pointer
Score* create_score(int x);
// TODO: Declare free_score function
// Takes a Score pointer, returns void
void free_score(Score *ptr);
// TODO: Declare score_get_points function (getter)
// Takes a const Score pointer, returns int
int score_get_points(const Score *ptr);
// TODO: Declare score_set_points function (setter)
// Takes a Score pointer and an int, returns void
void score_set_points(Score *ptr, int x);
// TODO: End include guards
#endif