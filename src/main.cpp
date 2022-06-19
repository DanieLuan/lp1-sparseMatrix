#include <iostream>
#include "../lib/MatrixEsp.h"

int main(){
    MatrixEsp matrix(3, 3);
    
     matrix.insert(5, 0, 0);
    matrix.insert(-5, 0, 1);
    matrix.insert(1, 0, 2);
   

    matrix.insert(4, 1, 1);
    matrix.insert(2, 1, 2);

    matrix.insert(8, 2, 0);
    matrix.insert(6, 2, 1);
    matrix.insert(3, 2, 2);

    matrix.print();
    std::cout << std::endl;
    for(size_t i = 0; i < matrix.matrixE.size(); i++){
        for(size_t j = 0; j < matrix.matrixE[i].listNode.size(); j++){
            std::cout << matrix.matrixE[i].listNode[j].index << " ";
        }
        std::cout << std::endl;
    }
    matrix.sort();
    std::cout << std::endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << matrix.matrixE[i].listNode[j].index << " ";
        }
        std::cout << std::endl;
    }

    matrix.print();

    return 0;
}