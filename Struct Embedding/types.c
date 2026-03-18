#include <stdio.h>
#include "types.h"

// TODO: Implement print_employee function
// - Takes a pointer to an Employee
// - Prints: "Employee: <name>"
// - Prints: "Age: <age>"
// - Prints: "ID: <employee_id>"
// - Access embedded person's data using arrow and dot syntax
void print_employee(Employee *emp) {
    // TODO: Print employee information
    // Hint: Access name with emp->person.name
    printf("Employee: %s\n",emp->person.name);
    printf("Age: %d\n",emp->person.age);
    printf("ID: %d\n",emp->employee_id);
}
