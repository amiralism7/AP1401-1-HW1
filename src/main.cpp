
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

        testfunc();
        // testing read_database
        Books inventory{read_database("../resources/inventory.txt")};
        
        std::cout << inventory[58].title << std::endl;
        // testing search
        std::cout << search(inventory, "Harry Potter and the Prisoner of Azkaban") << std::endl; //043965548X
        // testing order
        Books shopinglist{};
        std::cout << order(inventory, shopinglist, inventory[58].isbn) << std::endl;
        std::cout << inventory[58].title << std::endl;
        std::cout << shopinglist[0].title << std::endl;
        // testing get_receipt
        order(inventory, shopinglist, inventory[0].isbn);
        order(inventory, shopinglist, inventory[55].isbn);
        order(inventory, shopinglist, inventory[46].isbn);
        order(inventory, shopinglist, inventory[33].isbn);
        order(inventory, shopinglist, inventory[20].isbn);
        order(inventory, shopinglist, inventory[17].isbn);
        std::cout << get_receipt(shopinglist) << std::endl;
        
        
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