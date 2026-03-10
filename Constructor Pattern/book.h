// TODO: Add include guards using BOOK_H
#ifndef BOOK_H
#define BOOK_H
// TODO: Declare the Book struct with:
// - char *title (pointer to dynamically allocated string)
// - int pages
typedef struct{
    char *title;
    int pages;
}Book;
// TODO: Declare the create_book function that:
// - Takes a title string and page count
// - Returns a pointer to a newly created Book
Book *create_book(char *anyName, int page);
// TODO: Don't forget to close the include guard
#endif