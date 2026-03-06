// TODO: Add include guards using TIMER_H
#ifndef TIMER_H
#define TIMER_H
// TODO: Define the Timer struct with an int seconds member
typedef struct{
    int seconds;
}Timer;
// TODO: Declare timer_tick function (takes Timer pointer and int amount)
void timer_tick(Timer *self, int amount);
// TODO: Declare timer_reset function (takes Timer pointer)
void timer_reset(Timer *self);
// Don't forget to close the include guard
#endif
