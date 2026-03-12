#ifndef BOX_H
#define BOX_H

// TODO: Forward declare the Box struct (opaque pointer pattern)
// This hides the implementation details from users of this header
typedef struct Box Box;

// TODO: Declare create_box function
// Takes three integers (width, height, depth) and returns a Box pointer
Box* create_box(int width, int height, int depth);

// TODO: Declare destroy_box function
// Frees the allocated memory
void destroy_box(Box *b);

// TODO: Declare get_volume function
// Takes a const Box * and returns the volume
int get_volume(const Box *b);

// TODO: Declare set_dimensions function
// Takes a Box pointer and three new dimension values
// Returns int (1 for success, 0 if any dimension is negative or zero)
int set_dimensions(Box *b, int width, int height, int depth);

#endif
