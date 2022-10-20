#include<iostream>
#include<iomanip>
#include<vector>
#include"fstream"

// void testfunc();
// defining a Class: Book
struct Book
{
    std::string title;          // title of the book
    std::string author;         // author of the book
    float cost;                 // cost of the book
    std::string isbn;           // a unique string assigned to each book
    std::string language_code;  // language of the book
    int num_pages;              // number of pages
    std::string publisher;      // publisher of the book
    int count;                  // how many books left in the inventory
};

// defining an anlias: Books
using Books = std::vector<Book>;

namespace book{
    // declaring a function: read_database
    Books read_database(std::string filepath);


    // declaring a function: search
    std::string search(Books inventory, std::string title);

    // declaring a function: order
    bool order(Books& inventory, Books& shopinglist, std::string isbn);

    // declaring a function: get_receipt
    double get_receipt(Books shopinglist);
}