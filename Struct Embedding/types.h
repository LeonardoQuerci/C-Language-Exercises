#ifndef TYPES_H
#define TYPES_H

// TODO: Define the Person struct
// - name: character array of 50 characters
// - age: integer
typedef struct{
    char name[30];
    int age;
}Person;
// TODO: Define the Employee struct
// - person: embedded Person struct (first member)
// - employee_id: integer
typedef struct{
    Person person;
    int employee_id;
}Employee;
// Function declaration
void print_employee(Employee *emp);
#endif
