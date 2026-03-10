#include "counter.h"

// TODO: Implement counter_increment
// This function takes a pointer to Counter and increases its value by 1
void counter_increment(Counter *c){
    c->value++;
}
// TODO: Implement counter_get
// This function takes a pointer to Counter and returns its current value
int counter_get(Counter *c){
    return c->value;
}
