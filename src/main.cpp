#include <iostream>
#include "../lib/matrixEsp.h"

int main(){
    MatrixEsp matrix(3, 4);
    //matrix.print();
    
    matrix.insert(1, 0, 3);
    matrix.insert(3, 1, 1);
    matrix.insert(5, 2, 2);
    matrix.insert(3, 2, 3);

    matrix.print();
    return 0;
}