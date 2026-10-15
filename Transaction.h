#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
    private:
        int patronID;
        std::string bookTitle;
        std::string date;

    public:
        Transaction(int pID, const std::string& bTitle);
        ~Transaction() = default;

        void displayTransaction() const;
};

#endif