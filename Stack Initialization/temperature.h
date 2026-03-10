#ifndef TEMPERATURE_H
#define TEMPERATURE_H

// TODO: Define the Temperature struct with:
// - double celsius
// - char scale
typedef struct{
    double celsius;
    char scale;
} Temperature;

// TODO: Declare create_temperature function
// Takes a double value, returns Temperature by value
Temperature create_temperature(double value);
// TODO: Declare temperature_to_fahrenheit function
// Takes a const Temperature pointer, returns double
double temperature_to_fahrenheit(const Temperature *ptr);
#endif
