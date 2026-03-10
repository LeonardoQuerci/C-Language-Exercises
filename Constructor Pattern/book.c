#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

// TODO: Implement the create_book function
// Steps:
// 1. Allocate memory for the Book struct
// 2. Allocate memory for the title string (remember the null terminator!)
// 3. Copy the title into the newly allocated memory
// 4. Set the pages field
// 5. Return the pointer to the new Book
Book *create_book(char *anyName, int page){
    Book *b=malloc(sizeof(Book));
    b->title=malloc(strlen(anyName)+1);
    strcpy(b->title,anyName);
    b->pages=page;
    return b;
}


