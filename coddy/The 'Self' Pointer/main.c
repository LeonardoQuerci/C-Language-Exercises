#include <stdio.h>
#include "timer.h"

int main() {
    int initial_seconds, amount_to_add;
    scanf("%d", &initial_seconds);
    scanf("%d", &amount_to_add);
    
    // TODO: Create a Timer and initialize it with initial_seconds
    Timer h;
    h.seconds = initial_seconds;
    // TODO: Call timer_tick to add amount_to_add seconds
    timer_tick(&h,amount_to_add);
    // TODO: Print the current seconds in format: "After tick: {seconds}"
    printf("After tick: %d\n",h.seconds);
    // TODO: Call timer_reset to reset the timer
    timer_reset(&h);
    // TODO: Print the seconds again in format: "After reset: {seconds}"
    printf("After reset: %d",h.seconds);
    return 0;
}

