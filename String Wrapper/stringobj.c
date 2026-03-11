#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringobj.h"

// TODO: Implement create_string
// 1. Allocate memory for StringObject struct
// 2. Allocate memory for text (strlen + 1 for null terminator)
// 3. Copy the input string to the allocated text buffer
// 4. Return the pointer to the new StringObject
StringObject* create_string(const char *texto){
    StringObject *p= malloc(sizeof(StringObject));
    p->text=malloc(strlen(texto)+1);
    strcpy(p->text,texto);
    return p;
}
// TODO: Implement print_string
// Print in format: Text: {text}
void print_string(const StringObject *ptr){
    printf("Text: %s\n",ptr->text);
}
// TODO: Implement free_string
// 1. Check if pointer is NULL for safety
// 2. Free the text buffer first
// 3. Free the struct itself
void free_string(StringObject *ptr){
    if(ptr==NULL)return;
    free(ptr->text);
    free(ptr);
}