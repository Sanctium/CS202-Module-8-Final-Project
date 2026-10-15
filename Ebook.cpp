#include "Ebook.h"

#include <iostream>

// Constructor
Ebook::Ebook(std::string t, std::string a, Genre g, double size) : Book(t, a, g), fileSizeMB(size) {}

// Display book information
void Ebook::displayInfo() const {
    Book::displayInfo();
    std::cout << "File Size: " << fileSizeMB << " MB" << std::endl;
}

// Returns the file size in MB
double Ebook::getFileSize() const {
    return fileSizeMB;
}