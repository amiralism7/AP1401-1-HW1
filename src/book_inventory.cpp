#include "book_inventory.h"
#include "fstream"

//delete this after the test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void testfunc(){
    std::cout << "testfunc is running..." << std::endl;
}


// defining a function: read_database
Books read_database(std::string filepath){
    // try to open the file
    std::ifstream ifile{filepath};
    if (ifile.fail()){
        throw std::runtime_error("couldn't open the given directory.");
    }
    // the output of the function
    Books books{};
    //defining the temp variables
    std::string str{};
    std::string str2find{};
    std::string substr{};
    size_t substr_end{};
    std::string* arr{ new std::string[8] };
    Book book{};

    // while loop to read the file line by line
    while(std::getline(ifile, str)){
        // we try to find the indexes of comma, so we can seperate the book's attributes.

        // initalizing
        str2find = str;
        // finding the 8 first attributes
        for (size_t i{}; i<8; i++){
            substr_end = str2find.find(',');
            substr = str2find.substr(0, substr_end);
            str2find = str2find.substr(substr_end+1, str2find.length()-substr_end-1);
            arr[i] = substr;

            // std::cout<< "substr " << i << " is: " << arr[i] << std::endl;
        }
        // std::cout<< "substr " << 9 << " is: " << str2find << std::endl;
        
        // initializing the temp Book
        book.title = arr[1];
        book.author = arr[2];
        book.cost = std::stof(arr[3]);
        book.isbn = arr[4];
        book.language_code = arr[5];
        book.num_pages = std::stoi(arr[6]);
        book.publisher = arr[7];
        book.count = std::stoi(str2find);

        // adding the temp book to the vector books
        books.push_back(book);
    }

    //std::cout << "read_database has run..." << std::endl;
    ifile.close();
    delete[] arr;
    return books;
}