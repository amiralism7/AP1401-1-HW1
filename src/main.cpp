#include <iostream>
#include <gtest/gtest.h>
#include "book_inventory.h"
#include "regression.h"


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        std::cout<< "main.cpp is running..." << std::endl;

        // testing read_database
        Books inventory{book::read_database("../resources/inventory.txt")};
        
        std::cout << inventory[58].title << std::endl;
        // testing search
        std::cout << book::search(inventory, "Harry Potter and the Prisoner of Azkaban") << std::endl; //043965548X
        // testing order
        Books shopinglist{};
        std::cout << book::order(inventory, shopinglist, inventory[58].isbn) << std::endl;
        std::cout << inventory[58].title << std::endl;
        std::cout << shopinglist[0].title << std::endl;
        // testing get_receipt
        book::order(inventory, shopinglist, inventory[0].isbn);
        book::order(inventory, shopinglist, inventory[55].isbn);
        book::order(inventory, shopinglist, inventory[46].isbn);
        book::order(inventory, shopinglist, inventory[33].isbn);
        book::order(inventory, shopinglist, inventory[20].isbn);
        book::order(inventory, shopinglist, inventory[17].isbn);
        std::cout << book::get_receipt(shopinglist) << std::endl;
        
        std::cout << "*****************************************************************" << std::endl;
        
        // testing read_database
        Data data{regression::read_database("../resources/fish.txt")};
        std::cout << data.size() << std::endl;
        std::cout << data[0].size() << std::endl;
        std::cout << data[99][0] << " " << data[99][1] << " "  << data[99][2] << " "  << data[99][3] << " "  << data[99][4] << std::endl;

        std::vector<double> theta = regression::linear_regression(data, {0, 0, 0, 0}, 0.0000005);
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}