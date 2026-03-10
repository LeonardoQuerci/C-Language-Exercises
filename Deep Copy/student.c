#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
// TODO: Implement create_student
// - Allocate memory for a new Student struct
// - Allocate memory for the name string and copy the input name
// - Set the grade
// - Return the pointer to the new Student
Student* create_student(char *name, int grade){
    Student *s=malloc(sizeof(Student));
    s->name=malloc(strlen(name)+1);
    strcpy(s->name,name);
    s->grade=grade;
    return s;
}

// TODO: Implement clone_student
// - This is the key function for deep copy
// - Allocate fresh memory for a new Student struct
// - Allocate fresh memory for the name string (don't just copy the pointer!)
// - Copy the actual string data using strcpy or similar
// - Copy the grade value
// - Return the pointer to the cloned Student
Student* clone_student(const Student *origin){
    Student *clone = malloc(sizeof(Student));
    clone->name=malloc(strlen(origin->name)+1);
    strcpy(clone->name,origin->name);
    clone->grade=origin->grade;
    return clone;
}

// TODO: Implement free_student
// - Free the name string first
// - Then free the Student struct itself
void free_student(Student *str){
    if (str==NULL)return;
    free(str->name);
    free(str);
}