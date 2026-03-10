#include "temperature.h"

// TODO: Implement create_temperature
// - Create a local Temperature variable
// - Set celsius to the input value
// - Set scale to 'C'
// - Return the struct by value
Temperature create_temperature(double value){
    Temperature t;
    t.celsius=value;
    t.scale ='C';
    return t;
}


// TODO: Implement temperature_to_fahrenheit
// - Use formula: fahrenheit = celsius * 9.0 / 5.0 + 32.0
// - Return the calculated Fahrenheit value
double temperature_to_fahrenheit(const Temperature *ptr){
    return ptr->celsius*9.0/5.0+32;
}
