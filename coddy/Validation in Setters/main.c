#include <stdio.h>
#include "temperature.h"

int main() {
    // Read inputs
    int initial, valid_temp, invalid_temp;
    scanf("%d", &initial);
    scanf("%d", &valid_temp);
    scanf("%d", &invalid_temp);
    
    // TODO: Create a Temperature with the initial value
    Temperature *t=create_temperature(initial);
    // TODO: Print initial temperature
    // Format: "Initial: {degrees}"
    printf("Initial: %d\n",temp_get_degrees(t));
    // TODO: Attempt to set the invalid temperature
    // Print the result and show value remains unchanged
    // Format: "Set {invalid}: {0 or 1}"
    // Format: "After invalid: {degrees}"
    printf("Set %d: %d\n",invalid_temp, temp_set_degrees(t,invalid_temp));
    printf("After invalid: %d\n",temp_get_degrees(t));
    // TODO: Set the valid temperature
    // Print the success result and show updated value
    // Format: "Set {valid}: {0 or 1}"
    // Format: "After valid: {degrees}"
    printf("Set %d: %d\n",valid_temp,temp_set_degrees(t,valid_temp));
    printf("After valid: %d\n",temp_get_degrees(t));
    // TODO: Free the memory and print "Freed"
    free_temperature(t);
    printf("Freed");
    return 0;
}
