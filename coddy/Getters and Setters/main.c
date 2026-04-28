#include <stdio.h>
#include "score.h"

int main() {
    int initial_points, new_points;
    scanf("%d", &initial_points);
    scanf("%d", &new_points);
    
    // TODO: Create a Score with initial_points
    Score *s= create_score(initial_points);
    // TODO: Print the initial value using the getter
    // Format: "Initial: {points}"
    printf("Initial: %d\n",score_get_points(s));
    // TODO: Update the score using the setter with new_points
    score_set_points(s,new_points);
    // TODO: Print the updated value using the getter
    // Format: "Updated: {points}"
    printf("Updated: %d\n",score_get_points(s));
    // TODO: Free the score and print "Freed"
    free_score(s);
    printf("Freed");
    return 0;
}
