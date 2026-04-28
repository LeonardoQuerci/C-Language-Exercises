#include "timer.h"
#include <stdlib.h>

// TODO: Define the actual struct Timer here
// It should have two members:
// - int seconds
// - int running (1 for running, 0 for stopped)
struct Timer{
    int seconds;
    int running;
};
// TODO: Implement create_timer function
// - Allocate memory for the struct
// - Initialize seconds with the provided value
// - Set running to 1
// - Return the pointer
Timer* create_timer(int second){
    Timer *t=malloc(sizeof(Timer));
    t->seconds=second;
    t->running=1;
    return t;
}

// TODO: Implement free_timer function
// - Free the allocated memory
void free_timer(Timer *t){
    if(t==NULL)return;
    free(t);
}