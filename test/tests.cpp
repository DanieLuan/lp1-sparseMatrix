#include "tests.hpp"

void testConstructors(){
    std::cout << BGRN "\n---------[ CONSTRUCTORS TEST ]---------\n" reset;
    std::cout << BCYN  "NODE CONSTRUCTOR \n" reset;
    std::cout << CYN  "  Node(2, 9);\n\n" reset ;

    Node n(2,9);
    std::cout <<      "Node.value = " << n.value << "\n";
    std::cout <<      "Node.index = " << n.index << "\n\n";
    
    std::cout <<  BCYN "MATRIX CONSTRUCTOR\n" reset;
    MatrixEsp m(2,4);
    std::cout <<  CYN "  MatrixEsp(2, 4);\n" reset;
    std::cout << RED;
    m.print();
    std::cout << reset;

    std::cout << RED "OBS: Destructors are unnecessary while using STD::Vector.\n" reset;
}

void testInsert(){
    std::cout << BGRN   "\n---------[ INSERT TEST ]---------\n" reset;
    std::cout << BCYN    "[ TEST 1 - Insert default ]\n" reset;
    std::cout <<        "Insert(3,2,2)\n";
    std::cout <<        "Insert(1,0,0)\n";
    std::cout <<        "Insert(5,2,3)";
    MatrixEsp m(3,4);
    m.insert(3,2,2);
    m.insert(1,0,0);
    m.insert(5,2,3);
    std::cout << RED;
    m.print();
    std::cout << reset;
    std::cout << BCYN    "[ TEST 2 - Replace Insert ]\n" reset;
    std::cout <<        "Insert(6,2,2)\n";
    std::cout <<        "Insert(8,0,0)\n";
    std::cout <<        "Insert(9,2,3)";
    m.insert(6,2,2);
    m.insert(8,0,0);
    m.insert(9,2,3);
    std::cout << RED;
    m.print();
    std::cout << reset;
}

void testRemove(){
    std::cout << BGRN   "\n---------[ REMOVE TEST ]---------\n" reset;
    MatrixEsp m(3,4);
    m.insert(2,0,0);
    m.insert(4,0,1);
    m.insert(6,0,2);
    m.insert(8,0,3);

    m.insert(1,1,0);
    m.insert(3,1,1);
    m.insert(5,1,2);
    m.insert(7,1,3);

    m.insert(1,2,0);
    m.insert(1,2,1);
    m.insert(2,2,2);
    m.insert(5,2,3);

    std::cout << BCYN    "[ TEST 1 - Remove default ]\n" reset;
    std::cout <<         "Matrix before:";
    std::cout << RED;
    m.print();
    std::cout << reset;
    std::cout <<         "Remove(2,3); Remove(2,2); Remove(2,1); Remove(2,0);\n";
    std::cout <<         "Matrix after:";
    m.remove(2,2);
    m.remove(2,0);
    m.remove(2,1);
    m.remove(2,3);
    std::cout << RED;
    m.print();
    std::cout << reset;

    std::cout << BCYN    "\n[ TEST 2 - Remove unvalid position ]\n" reset;
    std::cout <<         "Matrix before:";

    std::cout << RED;
    m.print();
    std::cout << reset;

    std::cout <<         "\nRemove(4,5);\n";
    std::cout <<         "Matrix after:";
    m.remove(4,5);
    
    std::cout << RED;
    m.print();
    std::cout << reset;
   

}

void testGet(){
    std::cout << BGRN   "\n---------[ GET TEST ]---------\n" reset;
    std::cout <<         "Matrix to test:";
    MatrixEsp m(3,4);
    m.insert(3,2,2);
    m.insert(1,0,0);
    m.insert(5,2,3);
    std::cout << RED;
    m.print();
    std::cout << reset;
    std::cout << BCYN    "\n[ TEST 1 - Get a element ]\n" reset;
    std::cout <<         "get(2,2) = " << m.get(2,2) << std::endl;

    std::cout << BCYN    "\n[ TEST 2 - Get a non existing element ]\n" reset;
    std::cout <<         "get(0,2) = " << m.get(0,2) << std::endl;
}

void testSearch(){
    std::cout << BGRN   "\n---------[ SEARCH TEST ]---------\n" reset;
    std::cout <<         "Matrix to test:";
    MatrixEsp m(3,4);
    m.insert(7,1,1);
    m.insert(8,0,0);
    m.insert(1,2,3);
    std::cout << RED;
    m.print();
    std::cout << reset;

    std::cout << BCYN    "\n[ TEST 1 - Search a element ]\n" reset;
    int col, row;
    std::cout <<         "search(1,row, col)" << std::endl;

    if(m.search(1, row, col)){
        std::cout << "Value 1 found! Row = " << row << ", Col = " << col << "\n.";
    } else {
        std::cout << "Value not found!\n";
    }

    std::cout << BCYN    "\n[ TEST 2 - Search a non existing element ]\n" reset;
    std::cout <<         "search(3,row, col)" << std::endl;
    if(m.search(3, row, col)){
        std::cout << "Value 1 found! Row = " << row << ", Col = " << col << "\n.";
    } else {
        std::cout << "Value not found!\n";
    }
}

void testSave(){
    std::cout << BGRN   "\n---------[ SAVE TEST ]---------\n" reset;
    std::cout << CYN    "The files can be found at 'matrixSamples' directory.\n" reset;

    std::cout << BCYN    "\n[ TEST 1 - Save a matrix default ]\n" reset;
    MatrixEsp m1(3,4);
    m1.insert(3,2,2);
    m1.insert(1,0,0);
    m1.insert(5,2,3);
    m1.insert(7,1,2);
    m1.insert(9,1,1);
    std::cout <<         "Matrix:";
    std::cout << RED;
    m1.print();
    std::cout << reset;
    m1.saveMatrix("test/matrixSamples/save/matrixT1.txt");
    std::cout << "Expected file content:\n3x4\n0;0;1\n1;1;9\n1;2;7\n2;2;3\n2;3;5\n";

    std::cout << BCYN    "\n[ TEST 2 - Save a matrix with one element ]\n" reset;
    MatrixEsp m2(3,2);
    m2.insert(12,2,1);
    std::cout <<         "Matrix:";
    std::cout << RED;
    m2.print();
    std::cout << reset;
    m2.saveMatrix("test/matrixSamples/save/matrixT2.txt");
    std::cout << "Expected file content:3x2\n2;1;12\n";

    std::cout << BCYN    "\n[ TEST 3 - Save a empty matrix ]\n" reset;
    MatrixEsp m3(5,5);
    std::cout <<         "Matrix:";
    std::cout << RED;
    m3.print();
    std::cout << reset;
    m3.saveMatrix("test/matrixSamples/save/matrixT3.txt");
    std::cout << "Expected file content:5x5\n";
}

void testLoad(){
    std::cout << BGRN   "\n---------[ LOAD TEST ]---------\n" reset;
    std::cout << CYN    "The files can be found at 'matrixSamples' directory.\n" reset;
    
    std::cout << BCYN    "\n[ TEST 1 - Load a empty matrix AND change dimensions ]\n" reset;
    MatrixEsp m1(2,2);
    m1.insert(3,1,1);
    m1.insert(6,0,1);
    m1.insert(6,0,0);
    std::cout <<         "Original matrix:";
    std::cout << RED;
    m1.print();
    std::cout << reset;
    m1.loadMatrix("test/matrixSamples/load/matrixT1.txt");
    std::cout <<         "Loaded matrix:";
    std::cout << RED;
    m1.print();
    std::cout << reset;

    std::cout << BCYN    "\n[ TEST 2 - Load a matrix AND change dimensions ]\n" reset;
    MatrixEsp m2(2,2);
    m2.insert(3,1,1);
    m2.insert(6,0,1);
    m2.insert(6,0,0);
    std::cout <<         "Original matrix:";
    std::cout << RED;
    m2.print();
    std::cout << reset;
    m2.loadMatrix("test/matrixSamples/load/matrixT2.txt");
    std::cout <<         "Loaded matrix:";
    std::cout << RED;
    m2.print();
    std::cout << reset;
}
