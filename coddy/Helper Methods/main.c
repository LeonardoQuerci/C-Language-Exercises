#include <stdio.h>
#include "circle.h"

int main() {
    double radius;
    scanf("%lf", &radius);
    
    // TODO: Create a Circle struct with the given radius
    Circle c;
    c.radius=radius;
    // TODO: Use circle_area and circle_circumference helper methods
    // to calculate and print the results
    // Print format:
    printf("Area: %.2f\n", circle_area(&c));
    printf("Circumference: %.2f\n",circle_circumference(&c));
    
    return 0;
}
