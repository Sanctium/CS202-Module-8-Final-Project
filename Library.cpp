#include "Library.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// Display all books
void Library::displayBooks() const {
    for (const auto& book : books) {
        if (book == nullptr) {
            throw std::runtime_error("Null book found in the library.");
        }
        else {
            book->displayInfo();
        }
    }
}

// Book checkout function
void Library::checkoutBook(const std::shared_ptr<Patron> patron, const std::shared_ptr<Book> book) {

    // Validate pointers
    if (patron == nullptr) {
        throw std::invalid_argument("Patron pointer is null.");
    }

    if (book == nullptr) {
        throw std::invalid_argument("Book pointer is null.");
    }

    // Check that the book and patron exist
    if (std::find(books.begin(), books.end(), book) == books.end()) {
        throw std::runtime_error("Book not found in the library.");
    }

    if (std::find(patrons.begin(), patrons.end(), patron) == patrons.end()) {
        throw std::runtime_error("Patron not found in the library.");
    }

    // Prevent duplicate checkout
    if (patron->hasBorrowedBook(book)) {
        throw std::runtime_error("Patron has already borrowed this book.");
    }

    // Verify that the book is available
    if (book->getStatus() != BookStatus::Available) {
        throw std::runtime_error("Book is not available for checkout.");
    }

    // Complete the checkout process
    patron->borrowBook(book);

    // Record the transaction
    recordTransaction(std::make_shared<Transaction>(patron->getID(), book->getTitle()));
}

// Book return function
void Library::returnBook(const std::shared_ptr<Patron> patron, const std::shared_ptr<Book> book) {
    // Validate pointers
    if (patron == nullptr) {
        throw std::invalid_argument("Patron pointer is null.");
    }

    if (book == nullptr) {
        throw std::invalid_argument("Book pointer is null.");
    }

    // Check that the book and patron exist
    if (std::find(books.begin(), books.end(), book) == books.end()) {
        throw std::runtime_error("Book not found in the library.");
    }
    if (std::find(patrons.begin(), patrons.end(), patron) == patrons.end()) {
        throw std::runtime_error("Patron not found in the library.");
    }

    // Check if the patron has borrowed the book
    if (!patron->hasBorrowedBook(book)) {
        throw std::runtime_error("Patron has not borrowed this book.");
    }

    // Complete the return process
    patron->returnBook(book);

    // Record the transaction
    recordTransaction(std::make_shared<Transaction>(patron->getID(), book->getTitle()));
}

// Add a book
void Library::addBook(const std::shared_ptr<Book>& book) {
    if (book == nullptr) {
        throw std::invalid_argument("Cannot add a null book.");
    }

    if (std::find(books.begin(), books.end(), book) == books.end()) {
        books.push_back(book);
    }
}

// Remove a book
void Library::removeBook(const std::shared_ptr<Book>& book) {
    if (book == nullptr) {
        throw std::invalid_argument("Cannot remove a null book.");
    }

    auto it = std::find(books.begin(), books.end(), book);

    if (it == books.end()) {
        throw std::runtime_error("Book not found in the library.");
    }

    if (book->getStatus() == BookStatus::CheckedOut) {
        throw std::runtime_error("Cannot remove a book that is currently checked out.");
    }

    books.erase(it);
}

//Find a book by its title
std::shared_ptr<Book> Library::findBookByTitle(const std::string& title) const {
    for (const auto& book : books) {
        if (book != nullptr && book->getTitle() == title) {
            return book;
        }
    }

    throw std::runtime_error("Book with title '" + title + "' not found in the library.");
}

// Add a patron
void Library::addPatron(const std::shared_ptr<Patron>& patron) {
    if (patron == nullptr) {
        throw std::invalid_argument("Cannot add a null patron.");
    }

    // Prevent duplicate patron IDs
    for (const auto& existingPatron : patrons) {
        if (existingPatron == nullptr) {
            throw std::runtime_error("Null patron found in the library.");
        }

        if (existingPatron->getID() == patron->getID()) {
            throw std::runtime_error("A patron with this ID already exists.");
        }
    }

    patrons.push_back(patron);
}

// Remove a patron (they must have no borrowed books)
void Library::removePatron(const std::shared_ptr<Patron>& patron) {
    if (patron == nullptr) {
        throw std::invalid_argument("Cannot remove a null patron.");
    }

    auto it = std::find(patrons.begin(), patrons.end(), patron);

    if (it == patrons.end()) {
        throw std::runtime_error("Patron not found in the library.");
    }

    if (patron->hasBorrowedBooks()) {
        throw std::runtime_error("Cannot remove a patron who has borrowed books.");
    }

    patrons.erase(it);
}

// Find a patron by their ID
std::shared_ptr<Patron> Library::findPatronByID(int id) const {
    for (const auto& patron : patrons) {
        if (patron != nullptr && patron->getID() == id) {
            return patron;
        }
    }

    throw std::runtime_error("Patron with ID '" + std::to_string(id) + "' not found in the library.");
}

// Display all patrons
void Library::displayPatrons() const {
    for (const auto& patron: patrons) {
        if (patron == nullptr) {
            throw std::runtime_error("Null patron found in the library.");
        }
        else {
            patron->displayPatron();
        }
    }
}

// Display all transactions
void Library::displayTransactions() const {
    for (const auto& transaction : transactions) {
        if (transaction == nullptr) {
            throw std::runtime_error("Null transaction found in the library.");
        }
        else {
            transaction->displayTransaction();
        }
    }
}

// Record a transaction
void Library::recordTransaction(const std::shared_ptr<Transaction>& transaction) {
    if (transaction == nullptr) {
        throw std::invalid_argument("Cannot record a null transaction.");
    }

    transactions.push_back(transaction);
}