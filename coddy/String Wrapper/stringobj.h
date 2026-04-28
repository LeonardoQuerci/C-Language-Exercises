// TODO: Add include guards using STRINGOBJ_H
#ifndef STRINGOBJ_H
#define STRINGOBJ_H
// TODO: Define the StringObject struct with a char *text member
typedef struct {
    char *text;
}StringObject;
// TODO: Declare create_string function
// Takes const char * and returns StringObject *
StringObject* create_string(const char *texto);
// TODO: Declare print_string function
// Takes const StringObject * and displays the text
void print_string(const StringObject *ptr);
// TODO: Declare free_string function
// Takes StringObject * and frees all memory
void free_string(StringObject *ptr);
// TODO: End include guards
#endif