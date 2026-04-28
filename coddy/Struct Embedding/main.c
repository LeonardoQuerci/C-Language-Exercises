#include <stdio.h>
#include <string.h>
#include "types.h"

int main() {
    // Read input
    char name[50];
    int age;
    int employee_id;
    
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline
    scanf("%d", &age);
    scanf("%d", &employee_id);
    
    // TODO: Create an Employee variable
    Employee e;
    // TODO: Populate the embedded person's name and age
    // Hint: Use strcpy for the name, access with employee.person.name
    strcpy(e.person.name,name);
    e.person.age=age;
    // TODO: Set the employee_id
    e.employee_id=employee_id;
    // TODO: Call print_employee with a pointer to your employee
    print_employee(&e);
    return 0;
}
