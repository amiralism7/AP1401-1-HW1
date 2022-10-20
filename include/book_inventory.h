#include<iostream>
#include <vector>

void testfunc();
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

// declaring a function: read_database
Books read_database(std::string filepath);