#include <iostream>
#include "../lib/MatrixEsp.h"

int main(){
    MatrixEsp matrix(3, 3);

    matrix.insert(5, 0, 0);
    matrix.insert(-5, 0, 1);
    matrix.insert(1, 0, 2);

    matrix.insert(4, 1, 2);
    matrix.insert(2, 1, 0);

    matrix.insert(8, 2, 2);
    matrix.insert(6, 2, 1);
    matrix.insert(3, 2, 2);

    matrix.print();

    matrix.saveMatrix();
    matrix.loadMatrix();


    matrix.print();
    return 0;
}