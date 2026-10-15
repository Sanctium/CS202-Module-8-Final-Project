#include "Library.h"
#include "PrintedBook.h"
#include "Ebook.h"

#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>

//Display the menu
void displayMenu() {
    std::cout << " === Library Management System === " << std::endl;
    std::cout << "1. Display all books" << std::endl;
    std::cout << "2. Display all patrons" << std::endl;
    std::cout << "3. Check out a book" << std::endl;
    std::cout << "4. Return a book" << std::endl;
    std::cout << "5. Add a book" << std::endl;
    std::cout << "6. Add a patron" << std::endl;
    std::cout << "7. Display transaction history" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main() {
    Library library;
    bool running = true;
    
    while (running == true) {
        try {
            displayMenu();

            int choice;

            std::cout << "Enter your choice: ";

            if (!(std::cin >> choice)) {
                if (std::cin.eof()) {
                    running = false;
                    break;
                }

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                throw std::invalid_argument("Menu selection must be a number.");
            }

            //Remove the newline before using getline()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
                // Case for displaying all books
                case 1: {
                    library.displayBooks();
                    break;
                }

                // Case for displaying all patrons
                case 2: {
                    library.displayPatrons();
                    break;
                }

                // Case for checking out a book
                case 3: {
                    int patronID;
                    std::string title;

                    std::cout << "Enter patron ID: ";

                    // Checks validity of patronID input
                    if (!(std::cin >> patronID)) {
                        if (std::cin.eof()) {
                            running = false;
                            break;
                        }

                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Patron ID must be a number.");
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::cout << "Enter book title: ";
                    std::getline(std::cin, title);

                    // Checks validity of title input
                    if (title.empty()) {
                        throw std::invalid_argument("Book title cannot be empty.");
                    }

                    // Finds patron and book
                    auto patron = library.findPatronByID(patronID);
                    auto book = library.findBookByTitle(title);

                    // Checks out book
                    library.checkoutBook(patron, book);

                    std::cout << "Book checked out: " << title << std::endl;
                    std:: cout << "Patron ID: " << patronID << std::endl;

                    break;
                }

                // Case for returning a book
                case 4: {
                    int patronID;
                    std::string title;

                    std::cout << "Enter patron ID: ";

                    // Checks validity of patronID input
                    if (!(std::cin >> patronID)) {
                        if (std::cin.eof()) {
                            running = false;
                            break;
                        }

                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Patron ID must be a number.");
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    // Accepts title input
                    std::cout << "Enter book title: ";
                    std::getline(std::cin, title);

                    // Checks validity of title input
                    if (title.empty()) {
                        throw std::invalid_argument("Book title cannot be empty.");
                    }

                    // Finds patron and book
                    auto patron = library.findPatronByID(patronID);
                    auto book = library.findBookByTitle(title);

                    // Returns book
                    library.returnBook(patron, book);

                    std::cout << "Book returned: " << title << std::endl;
                    std::cout << "Patron ID: " << patronID << std::endl;

                    break;
                }

                // Case for adding a book
                case 5: {
                    std::string title;
                    std::string author;

                    // Accepts title input
                    std::cout << "Enter book title: " << std::endl;
                    std::getline(std::cin, title);

                    // Checks validity of title input
                    if (title.empty()) {
                        throw std::invalid_argument("Book title cannot be empty.");
                    }

                    // Accepts author input
                    std:: cout << "Enter author: ";
                    std::getline(std::cin, author);

                    if (author.empty()) {
                        throw std::invalid_argument("Author cannot be empty.");
                    }

                    std::cout << " === Select a genre === " << std::endl;
                    std::cout << "1. Fiction" << std::endl;
                    std::cout << "2. Non-Fiction" << std::endl;
                    std::cout << "3. Mystery" << std::endl;
                    std::cout << "4. Science Fiction" << std::endl;
                    std::cout << "5. Fantasy" << std::endl;
                    std::cout << "6. Biography" << std::endl;
                    std::cout << "7. History" << std::endl;
                    std::cout << "8. Romance" << std::endl;
                    std::cout << "Enter genre: " << std::endl;

                    int genreChoice;

                    // Checks validity of genreChoice input
                    if (!(std::cin >> genreChoice)) {
                        if (std::cin.eof()) {
                            running = false;
                            break;
                        }

                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Genre selection must be a number.");
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    // Assigns genre based on genreChoice input;
                    Genre genre;

                    switch (genreChoice) {
                        case 1: genre = Genre::Fiction; break;
                        case 2: genre = Genre::NonFiction; break;
                        case 3: genre = Genre::Mystery; break;
                        case 4: genre = Genre::ScienceFiction; break;
                        case 5: genre = Genre::Fantasy; break;
                        case 6: genre = Genre::Biography; break;
                        case 7: genre = Genre::History; break;
                        case 8: genre = Genre::Romance; break;
                        default: throw std::invalid_argument("Invalid genre selection.");
                    }

                    std:: cout << " === Select book type === " << std::endl;
                    std::cout << "1. Printed book" << std::endl;
                    std::cout << "2. Ebook" << std::endl;
                    std::cout << "Enter book type: " << std::endl;

                    int type;

                    // Checks validity of type input
                    if (!(std::cin >> type)) {
                        if (std::cin.eof()) {
                            running = false;
                            break;
                        }

                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Book type must be a number.");
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    // Assigns a pages value if type == printed book
                    if (type == 1) {
                        int pages;

                        std::cout << "Enter page count: ";

                        // Checks validity of pages input
                        if (!(std::cin >> pages)) {
                            if (std::cin.eof()) {
                                running = false;
                                break;
                            }

                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            throw std::invalid_argument("Page count must be a number.");
                        }

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        // Throws an error if pages is negative
                        if (pages <= 0) {
                            throw std::invalid_argument("Page count must be positive.");
                        }

                        // Creates a PrintedBook object based on prior inputs
                        auto book = std::make_shared<PrintedBook>(title, author, genre, pages);

                        library.addBook(book);
                    }
                    else if (type == 2) {
                        double size;

                        std::cout << "Enter file size in MB: ";

                        // Checks validity of size input
                        if (!(std::cin >> size)) {
                            if (std::cin.eof()) {
                                running = false;
                                break;
                            }

                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            
                            throw std::invalid_argument("File size must be a number.");
                        }

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        // Throws an error if size is negative
                        if (size < 0) {
                            throw std::invalid_argument("File size cannot be negative.");
                        }

                        // Creates an Ebook object based on prior inputs
                        auto book = std::make_shared<Ebook>(title, author, genre, size);

                        library.addBook(book);
                    }
                    else {
                        throw std::invalid_argument("Invalid book type selection.");
                    }

                    std::cout << "Book added: " << title << std::endl;
                    break;
                }

                // Case for adding a patron
                case 6: {
                    std::string name;
                    int id;

                    std::cout << "Enter patron name: " << std::endl;
                    std::getline(std::cin, name);

                    // Checks validity of name input
                    if (name.empty()) {
                        throw std::invalid_argument("Patron name cannot be empty.");
                    }

                    std::cout << "Enter patron ID: " << std::endl;

                    // Checks validity of ID input
                    if (!(std::cin >> id)) {
                        if (std::cin.eof()) {
                            running = false;
                            break;
                        }
                        
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Patron ID must be a number.");
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (id <= 0) {
                        throw std::invalid_argument("Patron ID must be positive.");
                    }

                    // Creates a patron object based on prior inputs
                    auto patron = std::make_shared<Patron>(name, id);

                    library.addPatron(patron);

                    std::cout << "Patron added: " << name << std::endl;
                    std::cout << "ID " << id << std::endl;
                    break;
                }

                // Case for displaying all transactions
                case 7: {
                    library.displayTransactions();
                    break;
                }

                // Case for exiting the system
                case 0: {
                    running = false;
                    std::cout << "Exiting..." << std::endl;
                    break;
                }

                default:
                    throw std::invalid_argument("Invalid menu selection.");
            }
        }

            catch (const std::invalid_argument& e) {
                std::cerr << "Invalid input: " << e.what() << std::endl;
            }

            catch (const std::runtime_error& e) {
                std::cerr << "Operation failed: " << e.what() << std::endl;
            }

            catch (const std::exception& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        }

    return 0;
}