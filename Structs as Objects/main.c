#include <stdio.h>
#include "counter.h"

int main() {
    // Read input
    int starting_value;
    int num_increments;
    scanf("%d", &starting_value);
    scanf("%d", &num_increments);
    
    // TODO: Create a Counter and initialize it with starting_value
    Counter c;
    c.value=starting_value;
    // TODO: Call counter_increment the specified number of times
    for (int i=0;i<num_increments;i++){
        counter_increment(&c);
    }
    // TODO: Use counter_get to retrieve the final value and print it
    // Print format: "Final value: {result}"
    printf("Final value: %d",counter_get(&c));
    return 0;
}

