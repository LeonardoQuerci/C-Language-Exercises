// TODO: Add include guards using TEMPERATURE_H
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
// TODO: Define the Temperature struct with a double celsius member
typedef struct{
    double celsius;
}Temperature;
// TODO: Declare temp_display - takes a const pointer to Temperature (read-only)
void temp_display(const Temperature *ptr);
// TODO: Declare temp_adjust - takes a regular pointer to Temperature and a double amount (modifying)
void temp_adjust(Temperature *ptr, double amount);
// TODO: Declare temp_to_fahrenheit - takes a const pointer to Temperature and returns double (read-only)
double temp_to_fahrenheit(const Temperature *ptr);
// TODO: Close include guards
#endif
