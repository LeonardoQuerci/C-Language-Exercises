#include <stdio.h>
#include "box.h"

int main() {
    // Read initial dimensions
    int width, height, depth;
    scanf("%d", &width);
    scanf("%d", &height);
    scanf("%d", &depth);
    
    // Read new dimensions to attempt
    int new_w, new_h, new_d;
    scanf("%d", &new_w);
    scanf("%d", &new_h);
    scanf("%d", &new_d);
    
    // TODO: Create a Box with initial dimensions
    Box *b= create_box(width,height,depth);
    // TODO: Print initial volume in format: "Volume: {volume}"
    printf("Volume: %d\n",get_volume(b));
    // TODO: Attempt to set new dimensions and store the result
    // TODO: Print whether set succeeded in format: "Set: {0 or 1}"
    printf("Set: %d\n",set_dimensions(b,new_w,new_h,new_d));    
    // TODO: Print the resulting volume in format: "Volume: {volume}"
    printf("Volume: %d\n",get_volume(b));
    // TODO: Destroy the box and print "Destroyed"
    destroy_box(b);
    printf("Destroyed");
    return 0;
}
