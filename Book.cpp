#include "Book.h"

#include <iostream>

// Constructor
Book::Book(std::string t, std::string a, Genre g) : title(t), author(a), genre(g), status(BookStatus::Available) {}


// Display book information
void Book::displayInfo() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genreToString(genre) << std::endl;
    std::cout << "Status: " << statusToString(status) << std::endl;
}

// Update the book's status
void Book::setStatus(BookStatus s) {
    status = s;
}

// Return the book's title
std::string Book::getTitle() const {
    return title;
}

// Return the book's status
BookStatus Book::getStatus() const {
    return status;
}

// Convert genre enum values into strings
std::string genreToString(Genre genre) {
    switch (genre) {
        case Genre::Fiction: return "Fiction";
        case Genre::NonFiction: return "Non-Fiction";
        case Genre::Mystery: return "Mystery";
        case Genre::ScienceFiction: return "Science Fiction";
        case Genre::Fantasy: return "Fantasy";
        case Genre::Biography: return "Biography";
        case Genre::History: return "History";
        case Genre::Romance: return "Romance";
        default: return "Unknown Genre";
    }
}

// Convert status enum values into strings
std::string statusToString(BookStatus status) {
    switch (status) {
        case BookStatus::Available: return "Available";
        case BookStatus::CheckedOut: return "Checked Out";
        default: return "Unknown Status";
    }
}

// Output book information
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Author: " << book.author
       << ", Genre: " << genreToString(book.genre)
       << ", Status: " << statusToString(book.status);

    return os;
}