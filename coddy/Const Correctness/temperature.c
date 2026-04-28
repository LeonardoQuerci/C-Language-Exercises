#include <stdio.h>
#include "temperature.h"

// TODO: Implement temp_display
// Should print: "Current: %.1fC\n"
// Remember: const pointer means you cannot modify the struct's data
void temp_display(const Temperature *ptr){
    printf("Current: %.1fC\n",ptr->celsius);
}
// TODO: Implement temp_adjust
// Should add the amount to the celsius value
// This function CAN modify the struct because it doesn't use const
void temp_adjust(Temperature *ptr, double amount){
    ptr->celsius+=amount;
}
// TODO: Implement temp_to_fahrenheit
// Should return: celsius * 9.0 / 5.0 + 32.0
// Remember: const pointer means you cannot modify the struct's data
double temp_to_fahrenheit(const Temperature *ptr){
    return ptr->celsius*9.0/5+32;
}

