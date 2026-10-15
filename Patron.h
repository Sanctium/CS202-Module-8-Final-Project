#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Book.h"

class Patron {
    private:
        std::string name;
        int id;
        std::vector<std::shared_ptr<Book>> borrowedBooks;
    
    public:
        // Constructor and destructor
        Patron(std::string n, int i);
        ~Patron() = default;

        // Get the patron's ID
        int getID() const;

        // Borrow and return books
        void borrowBook(const std::shared_ptr<Book>& book);
        void returnBook(const std::shared_ptr<Book>& book);

        // Borrowing status checks
        bool hasBorrowedBook(const std::shared_ptr<Book>& book) const;
        bool hasBorrowedBooks() const;
        
        // Display patron information
        void displayPatron() const;

        // Comparison and output operators
        bool operator==(const Patron& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Patron& patron);

};

#endif