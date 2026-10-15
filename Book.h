#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ostream>

// Book genres
enum class Genre {
    Fiction,
    NonFiction,
    Mystery,
    ScienceFiction,
    Fantasy,
    Biography,
    History,
    Romance
};

// Book availability status
enum class BookStatus {
    Available,
    CheckedOut
};

// Enum-to-string conversion functions
std::string genreToString(Genre genre);
std::string statusToString(BookStatus status);

class Book {
    protected:
        std::string title;
        std::string author;
        Genre genre;
        BookStatus status;
    public:
        // Constructor and destructor
        Book(std::string t, std::string a, Genre g);
        virtual ~Book() = default;

        // Display book information
        virtual void displayInfo() const;
        void setStatus(BookStatus s);

        // Gets status and title
        BookStatus getStatus() const;
        std::string getTitle() const;

        // Comparison and output operators
        bool operator==(const Book& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

#endif