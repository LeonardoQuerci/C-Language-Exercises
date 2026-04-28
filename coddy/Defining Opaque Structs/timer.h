#ifndef TIMER_H
#define TIMER_H

// TODO: Forward declare the Timer struct (opaque pointer pattern)
// Hint: Use "struct Timer;" without defining the body
typedef struct Timer Timer;
// TODO: Declare create_timer function
// Takes an integer for seconds, returns a Timer pointer
Timer* create_timer(int second);
// TODO: Declare free_timer function
// Takes a Timer pointer and cleans up
void free_timer(Timer *t);
#endif
