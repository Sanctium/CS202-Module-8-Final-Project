#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Patron.h"
#include "Transaction.h"

#include <vector>
#include <memory>
#include <string>

class Library {
    private:
        std::vector<std::shared_ptr<Book>> books;
        std::vector<std::shared_ptr<Patron>> patrons;
        std::vector<std::shared_ptr<Transaction>> transactions;

    public:
        Library() = default;
        ~Library() = default;

        // Book checkout and return functions
        void checkoutBook(const std::shared_ptr<Patron> patron, const std::shared_ptr<Book> book);
        void returnBook(const std::shared_ptr<Patron> patron, const std::shared_ptr<Book> book);

        // Book management functions
        void addBook(const std::shared_ptr<Book>& book);
        void removeBook(const std::shared_ptr<Book>& book);
        void displayBooks() const;

        // Patron management functions
        void addPatron(const std::shared_ptr<Patron>& patron);
        void removePatron(const std::shared_ptr<Patron>& patron);
        void displayPatrons() const;

        // Transaction management functions
        void displayTransactions() const;
        void recordTransaction(const std::shared_ptr<Transaction>& transaction);

        // Search functions
        std::shared_ptr<Book> findBookByTitle(const std::string& title) const;
        std::shared_ptr<Patron> findPatronByID(int id) const;
};

#endif