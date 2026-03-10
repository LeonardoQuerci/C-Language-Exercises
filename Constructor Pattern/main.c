#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main() {
    char title[256];
    int pages;
    
    // Read input
    fgets(title, sizeof(title), stdin);
    // Remove newline if present
    for (int i = 0; title[i]; i++) {
        if (title[i] == '\n') {
            title[i] = '\0';
            break;
        }
    }
    scanf("%d", &pages);
    
    // TODO: Use create_book to create a new book with the provided values
    Book *b=create_book(title,pages);
    // TODO: Print the book information in the required format:
    // Title: {title}
    // Pages: {pages}
    printf("Title: %s\n",b->title);
    printf("Pages: %d\n",b->pages);
    // TODO: Don't forget to free allocated memory when done
    free(b);
    return 0;
}
