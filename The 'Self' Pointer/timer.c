#include "timer.h"

// TODO: Implement timer_tick function
// It should accept a Timer *self and an int amount
// Add the amount to the timer's seconds
void timer_tick(Timer *self,int amount){
    for (int i=0;i<amount;i++){
        self->seconds++;
    }
}
// TODO: Implement timer_reset function
// It should accept a Timer *self
// Set its seconds to zero
void timer_reset(Timer *self){
    self->seconds=0;
}
