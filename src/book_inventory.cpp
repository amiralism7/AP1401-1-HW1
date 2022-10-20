#include "book_inventory.h"

// defining a function: read_database
Books book::read_database(std::string filepath){
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

// defining a function: read_database
std::string book::search(Books inventory, std::string title){
    std::string isbn{"none"};

    int comp{};
    for (size_t i{}; i < inventory.size(); i++) {
        comp = title.compare(inventory[i].title);
        if (comp == 0)
            isbn = inventory[i].isbn;
    }
    return isbn;

}

// defining a function: order
bool book::order(Books& inventory, Books& shopinglist, std::string isbn){
    int comp{};
    size_t i{0};
    for (; i < inventory.size(); i++) {
        comp = isbn.compare(inventory[i].isbn);
        if (comp == 0) {
            inventory[i].count--;
            shopinglist.push_back(inventory[i]);
            break;
        }
    }
    if (i == inventory.size())
        return false;
    return true;
}

// defining a function: get_receipt
double book::get_receipt(Books shopinglist){
    double total{0};
    std::cout << std::fixed;
    std::cout << "*****************************************************************" << std::endl;
    std::cout << "|    Title                  |    ISBN         |    Price        |" << std::endl;
    std::cout << "|---------------------------------------------------------------|" << std::endl;
    
    for (size_t i{}; i < shopinglist.size(); i++) {
        // summing up the prices
        total += shopinglist[i].cost;

        // printing title
        std::cout << "|    ";
        if (shopinglist[i].title.length() > 18){
            std::cout << shopinglist[i].title.substr(0, 16) << "...";
        }
        else{
            std::cout << shopinglist[i].title;
            for (size_t j{}; j < 19-shopinglist[i].title.length(); j++)
                std::cout << " ";
        }
        std::cout << "    |    ";
        
        // printing isbn
        if (shopinglist[i].isbn.length() > 10){
            std::cout << shopinglist[i].isbn.substr(0, 8) << "...";
        }
        else{

            std::cout << shopinglist[i].isbn;
            for (size_t j{}; j < 13-shopinglist[i].isbn.length(); j++){
                std::cout << " ";
            }
        }
        std::cout << "|    ";

        // printing cost
        if (shopinglist[i].cost < 10)
            std::cout << std::setprecision(6) << shopinglist[i].cost;
        else 
            std::cout << std::setprecision(5) << shopinglist[i].cost;
        std::cout << "$    |" << std::endl;
    }
    std::cout << "|---------------------------------------------------------------|" << std::endl;
    std::cout << "|                           |    Total Price  |    ";

    if (total >= 10 && total <= 100)
        std::cout << std::setprecision(5) << total << "$    |" << std::endl;
    else if (total >= 100 && total <= 1000)
        std::cout << std::setprecision(4) << total << "$    |" << std::endl;
    else if (total >= 1000)
        std::cout << std::setprecision(3) << total << "$    |" << std::endl;
    else 
        std::cout << std::setprecision(6) << total << "$    |" << std::endl;
    std::cout << "*****************************************************************" << std::endl;

    return total;
}