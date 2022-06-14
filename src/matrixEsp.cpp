#include <iostream>
#include "../lib/matrixEsp.h"

Node::Node(int val, int idx){
    value = val;
    index = idx;
}

List::List(){
    index = -1;
    length = 0;
}

MatrixEsp::MatrixEsp(int row_, int col_){
    col = col_;
    row = row_;
    matrixE.resize(row);
}

void List::insertRow(Node temp){
    listNode.push_back(temp);
    length++;
}
void MatrixEsp::insert(int val, int row_, int col_){
    Node temp(val, col_);
    matrixE[row_].insertRow(temp);
}

void MatrixEsp::print(){
    for(int i = 0; i < row; i++){
        for(int j = 0, k = 0; j < col; j++){
            if(j == matrixE[i].listNode[k].index){
                std::cout << matrixE[i].listNode[k].value << " ";
                k++;
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

bool MatrixEsp::posExists(int row_, int col_){
    if(matrixE[row_].listNode[col].index == col_ && matrixE[row_].index == row_){
        return true;
    } else {
        return false;
    }

}