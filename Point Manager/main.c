#include <stdio.h>
#include "point.h"

int main() {
    // Read input values
    int x, y, dx, dy;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &dx);
    scanf("%d", &dy);
    
    // TODO: Create a Point with initial coordinates (x, y)
    Point p;
    p.x=x;
    p.y=y;
    // TODO: Print the initial position using point_print
    point_print(&p);
    // TODO: Move the point by (dx, dy) using point_move
    point_move(&p,dx,dy);
    // TODO: Print the new position using point_print
    point_print(&p);
    return 0;
}
