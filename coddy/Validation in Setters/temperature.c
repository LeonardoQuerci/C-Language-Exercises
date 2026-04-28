#include <stdlib.h>
#include "temperature.h"

// TODO: Define the actual struct Temperature with a hidden int degrees member
struct Temperature{
    int degrees;
};
// TODO: Implement create_temperature
// Allocate memory and initialize with the given degrees value
Temperature* create_temperature(int x){
    Temperature *temp=malloc(sizeof(Temperature));
    temp->degrees=x;
    return temp;
}
// TODO: Implement free_temperature
// Free the allocated memory
void free_temperature(Temperature *temp){
    if(temp==NULL)return;
    free(temp);
}
// TODO: Implement temp_get_degrees
// Return the current temperature value
int temp_get_degrees(Temperature *temp){
    return temp->degrees;    
}
// TODO: Implement temp_set_degrees
// Only accept values between -50 and 150 (inclusive)
// Return 0 and leave unchanged if outside range
// Return 1 and update value if valid
int temp_set_degrees(Temperature *temp, int x){
    if(x>=-50 && x<=150){
        temp->degrees=x;
        return 1;
    }else{
        return 0;
    }
}