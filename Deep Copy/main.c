#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    char name[100];
    int grade;
    
    // Read input
    scanf("%s", name);
    scanf("%d", &grade);
    
    // TODO: Create a student with the provided name and grade
    Student *origin = create_student(name,grade);
    // TODO: Create a clone of the student
    Student *clone= clone_student(origin);
    // TODO: Print the original student's information
    // Format: "Original: {name}, Grade: {grade}"
    printf("Original: %s, Grade: %d\n",origin->name,origin->grade);
    // TODO: Print the clone's information
    // Format: "Clone: {name}, Grade: {grade}"
    printf("Clone: %s, Grade: %d\n",clone->name,clone->grade);
    // TODO: Free both students
    free_student(origin);
    free_student(clone);
    // Print confirmation
    printf("Both freed\n");
    
    return 0;
}
