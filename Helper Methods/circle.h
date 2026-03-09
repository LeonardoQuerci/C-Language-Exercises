// TODO: Add include guards using CIRCLE_H
#ifndef CIRCLE_H
#define CIRCLE_H
// TODO: Define the Circle struct with a double radius member
typedef struct{
    double radius;
}Circle;
// TODO: Declare circle_area function
// Takes a const pointer to Circle, returns double
double circle_area(const Circle *c);
// TODO: Declare circle_circumference function
// Takes a const pointer to Circle, returns double
double circle_circumference(const Circle *c);
// TODO: Close include guards
#endif