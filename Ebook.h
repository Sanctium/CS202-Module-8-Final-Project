#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class Ebook : public Book {
private:
    double fileSizeMB;

public:
    // Constructor and destructore
    Ebook(std::string t, std::string a, Genre g, double size);
    ~Ebook() = default;

    // Display book information
    void displayInfo() const override;

    // Gets the file size in MB
    double getFileSize() const;
};

#endif