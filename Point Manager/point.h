// TODO: Add include guards using POINT_H
#ifndef POINT_H
#define POINT_H
// TODO: Define the Point struct with x and y integer members
typedef struct{
    int x;
    int y;
}Point;
// TODO: Declare point_move function
// - Takes a pointer to Point and two integers (dx, dy)
// - Modifies the point's position
void point_move(Point *p, int dx, int dy);
// TODO: Declare point_print function
// - Takes a const pointer to Point
// - Should not modify the point
void point_print(const Point *p);
// TODO: Close include guards
#endif