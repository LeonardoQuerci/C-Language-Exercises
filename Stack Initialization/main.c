#include <stdio.h>
#include "temperature.h"

int main() {
    double celsius_input;
    scanf("%lf", &celsius_input);
    
    // TODO: Use create_temperature to create a Temperature struct
    Temperature t = create_temperature(celsius_input);
    // TODO: Print the Celsius value using %.2f format
    printf("Celsius: %.2f\n",t.celsius);
    // TODO: Use temperature_to_fahrenheit to convert and print the Fahrenheit value
    printf("Fahrenheit: %.2f\n",temperature_to_fahrenheit(&t));
    return 0;
}
