#include <stdio.h>
#include "timer.h"

int main() {
    int seconds;
    scanf("%d", &seconds);
    
    // TODO: Create a timer with the provided seconds value
    Timer *t = create_timer(seconds);
    // TODO: Print "Timer created"
    printf("Timer created\n");
    // TODO: Free the timer
    free_timer(t);
    // TODO: Print "Timer freed"
    printf("Timer freed\n");
    return 0;
}
