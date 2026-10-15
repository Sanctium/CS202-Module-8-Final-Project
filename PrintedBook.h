#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"

class PrintedBook : public Book {
    private:
        int numPages;
    public:
        // Constructor and destructor
        PrintedBook(std::string t, std::string a, Genre g, int pages);
        ~PrintedBook() = default;

        // Display book information
        void displayInfo() const override;

        // Gets the number of pages
        int getNumPages() const;
    };

#endif