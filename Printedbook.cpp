#include "PrintedBook.h"

#include <iostream>

// Constructor
PrintedBook::PrintedBook(std::string t, std::string a, Genre g, int pages) : Book(t, a, g), numPages(pages) {}

// Display information about the printed book
void PrintedBook::displayInfo() const {
    Book::displayInfo();

    std::cout << "Page Count: " << numPages << std::endl;
}

// Returns the number of pages
int PrintedBook::getNumPages() const {
    return numPages;
}