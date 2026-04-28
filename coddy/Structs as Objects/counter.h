// TODO: Add include guards using COUNTER_H
#ifndef COUNTER_H
#define COUNTER_H
// TODO: Define the Counter struct with a single int value member
typedef struct {
    int value;
}Counter;
// TODO: Declare counter_increment function
// Takes a pointer to Counter and increases its value by 1
void counter_increment(Counter *c);
// TODO: Declare counter_get function
// Takes a pointer to Counter and returns its current value
int counter_get(Counter *c);
// TODO: Close include guards
#endif
