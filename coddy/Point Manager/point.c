#include <stdio.h>
#include "point.h"

// TODO: Implement point_move
// - Add dx to the point's x coordinate
// - Add dy to the point's y coordinate
void point_move(Point *p, int dx, int dy){
    p->x+=dx;
    p->y+=dy;
}

// TODO: Implement point_print
// - Use a const pointer since we're only reading
// - Output format: Point: ({x}, {y})
void point_print(const Point *p){
    printf("Point: (%d, %d)\n",p->x,p->y);
}
