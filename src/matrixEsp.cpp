#include <iostream>
#include "../lib/matrixEsp.h"

Node::Node(){
    value = 0;
    index = -1;
    next = nullptr;
}
Node::~Node(){
    delete[] next;
    next = nullptr;
}

List::List(){
    listNode = nullptr;
    index = -1;
}
List::~List(){
    delete[] listNode;
    listNode = nullptr;
}

MatrixEsp::MatrixEsp(int row_, int col_){
    col = col_;
    row = row_;
    matrix = new List[row];
}
MatrixEsp::~MatrixEsp(){
    delete[] matrix;
    matrix = nullptr;
}

void MatrixEsp::print(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i].index == -1){
                std::cout << "0 0 0 ";
                break;
            }
        }
        std::cout << std::endl;
    }
}