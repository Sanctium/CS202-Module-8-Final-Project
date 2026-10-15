#include "Patron.h"
#include "Book.h"

#include <iostream>
#include <algorithm>
#include <memory>
#include <stdexcept>

// Constructor
Patron::Patron(std::string n, int i) : name(n), id(i) {}


// Return the patron's ID
int Patron::getID() const {
    return id;
}

// Borrow a book
void Patron::borrowBook(const std::shared_ptr<Book>& book) {
    // Check for errors: null book, book not available, or already borrowed
    if (book == nullptr) {
        throw std::invalid_argument("Cannot borrow a null book.");
    }

    if (hasBorrowedBook(book)) {
        throw std::runtime_error("Patron has already borrowed this book.");
    }

    if (book->getStatus() != BookStatus::Available) {
    throw std::runtime_error("Book is not available for borrowing.");
    }

    // Add the book to the borrowed list and update its status
    borrowedBooks.push_back(book);
    book->setStatus(BookStatus::CheckedOut);
}

// Return a book
void Patron::returnBook(const std::shared_ptr<Book>& book) {
    if (book == nullptr) {
        throw std::invalid_argument("Cannot return a null book.");
    }

    // Check if the book is in the borrowed list
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);

    // If the patron hasn't borrowed the book, throw an error
    if (it == borrowedBooks.end()) {
        throw std::runtime_error("This book was not borrowed by the patron.");
    }

    borrowedBooks.erase(it);
    book->setStatus(BookStatus::Available);
}

// Display patron information
void Patron::displayPatron() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Borrowed Books: " << borrowedBooks.size() << std::endl;

    for (const auto& book : borrowedBooks) {
        if (book == nullptr) {
            throw std::runtime_error("Null book found.");
        }

        std::cout << *book << std::endl;
    }
}

// Check if the patron has borrowed a specific book
bool Patron::hasBorrowedBook(const std::shared_ptr<Book>& book) const {
    return std::find(borrowedBooks.begin(), borrowedBooks.end(), book) != borrowedBooks.end();
}

// Check if the patron has borrowed any books
bool Patron::hasBorrowedBooks() const {
    return !borrowedBooks.empty();
}

// Compare patrons based on their ID
bool Patron::operator==(const Patron& other) const {
    return id == other.id;
}

// Output patron information
std::ostream& operator<<(std::ostream& os, const Patron& patron) {
    os << "Name: " << patron.name << ", ID: " << patron.id
       << ", Borrowed Books: " << patron.borrowedBooks.size();
    return os;
}