#include "Transaction.h"

#include <iostream>
#include <ctime>
#include <stdexcept>

Transaction::Transaction(int pID, const std::string& bTitle) : patronID(pID), bookTitle(bTitle) {
    // Get the current date
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    // Format the date as MM-DD-YY
    char dateBuffer[11];

    if (localTime == nullptr) {
        throw std::runtime_error("Failed to get local time.");
    }

    std::strftime(dateBuffer, sizeof(dateBuffer), "%m-%d-%y", localTime);
    date = dateBuffer;
}

// Display the transaction details
void Transaction::displayTransaction() const {
    std::cout << "Patron ID: " << patronID << std::endl;
    std::cout << "Book Title: " << bookTitle << std::endl;
    std::cout << "Transaction Date: " << date << std::endl;
}