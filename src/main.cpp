
#include <iostream>
#include <gtest/gtest.h>
#include "book_inventory.h"
#include "regression.h"


int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        // debug section
        std::cout<< "main.cpp is running..." << std::endl;

        testfunc();
        Books a{};
        a = read_database("../resources/inventory.txt");
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