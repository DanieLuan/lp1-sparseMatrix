#include <iostream>
#include "../lib/MatrixEsp.h"
#include "../test/tests.hpp"

int main(){
    std::cout << BRED "\n.......[ RUN TESTS FUNCTIONS ].......\n" reset;
    std::cout << RED "Test functions for the 'matrixEsp' class." "\n" reset;
    
    testConstructors();
    testInsert();
    testRemove();
    testGet();
    testSearch();
    testSave();
    testLoad();

    return 0;
}