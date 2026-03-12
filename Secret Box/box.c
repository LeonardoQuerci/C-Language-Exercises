#include <stdlib.h>
#include "box.h"

// TODO: Define the actual struct Box with three members:
// int width, int height, int depth
struct Box{
    int width;
    int height;
    int depth;
};

// TODO: Implement create_box
// Allocate memory for a Box, initialize with given dimensions, return pointer
Box* create_box(int width, int height, int depth){
    Box *b=malloc(sizeof(Box));
    b->width=width;
    b->height=height;
    b->depth=depth;
}

// TODO: Implement destroy_box
// Free the allocated memory
void destroy_box(Box *b){
    if(b==NULL)return;
    free(b);
}

// TODO: Implement get_volume
// Return width * height * depth
int get_volume(const Box *b){
    return b->width*b->height*b->depth;
}

// TODO: Implement set_dimensions
// Validate that all three values are positive (greater than zero)
// If any value fails validation, reject the entire update and return 0
// If all valid, update dimensions and return 1
int set_dimensions(Box *b, int width, int height, int depth){
    if (width>0 && height>0 && depth>0){
        b->width=width;
        b->height=height;
        b->depth=depth;
        return 1;
    }else{
        return 0;
    }
}
