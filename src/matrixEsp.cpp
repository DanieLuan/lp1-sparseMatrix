#include <iostream>
#include "../lib/MatrixEsp.h"

Node::Node(int val, int idx){
    value = val;
    index = idx;
}

List::List(){
    index = -1;
}

MatrixEsp::MatrixEsp(int row_, int col_){
    col = col_;
    row = row_;
    matrixE.resize(row);
    for(int i = 0; i < row; i++){
        matrixE[i].index = i;
    }
}

void List::insertRow(Node temp){
    listNode.push_back(temp);
}
void MatrixEsp::insert(int val, int row_, int col_){

    if(row_ < 0 || row_ > row || col_ < 0 || col_ > row){
        return;
    }
    bool verify = false;
    for(size_t i = 0; i < matrixE[row_].listNode.size(); i++){
        if(matrixE[row_].listNode[i].index == col_){
            matrixE[row_].listNode[i].value = val;
            verify = true;
        }
    }
    if(verify == false){
        Node temp(val, col_);
        matrixE[row_].insertRow(temp);
    }
}

void MatrixEsp::print(){
    std::cout << std::endl;
    for(int i = 0; i < row; i++){
        for(int j = 0, k = 0; j < col; j++){
            int size = matrixE[i].listNode.size();
            if(size == 0){
                for(int r = 0; r < col; r++){
                    std::cout << "0 ";
                    j = col;
                }
            } else {
                if(j == matrixE[i].listNode[k].index){
                std::cout << matrixE[i].listNode[k].value << " ";
                k++;
                } else {
                    std::cout << "0 ";
                }
            }
            
        }
        std::cout << std::endl;
    }
}

void MatrixEsp::remove(int row_, int col_){
    if((row_ < 0 || row_ > row || col_ < 0 || col_ > row)){ //FALTA FAZER OS ESPAÇOS CERTOS
        return;
    }
    for(size_t i = 0; i < matrixE[row_].listNode.size(); i++){
        if(matrixE[row_].listNode[i].index == col_){ //size_t and int comparison
            if(col_ == matrixE[row_].listNode.size()){
                matrixE[row_].listNode.pop_back();
            } else {
                matrixE[row_].listNode.erase(matrixE[row_].listNode.begin()+(i));
            }
            matrixE[row_].listNode.shrink_to_fit();
        }
    }
}

int MatrixEsp::get(int row_, int col_){
    if((row_ < 0 || row_ > row || col_ < 0 || col_ > row)){ //FALTA FAZER OS ESPAÇOS CERTOS
        return 0;
    }
    for(size_t i = 0; i < matrixE[row_].listNode.size(); i++){
        if(col_ == matrixE[row_].listNode[i].index){
            return matrixE[row_].listNode[i].value;
        }
    }
    return 0;
}

bool MatrixEsp::search(int val, int &row_, int &col_){
    for(size_t i = 0; i < matrixE.size(); i++){
        for(size_t j = 0; j < matrixE[i].listNode.size(); j++){
            if(matrixE[i].listNode[j].value == val){
                std::cout << matrixE[i].listNode[j].value << "==" << val << "\n";
                row_ = matrixE[i].index;
                col_ = matrixE[i].listNode[j].index;
                return true;
            }
        }
    }
    return false;
}

void swapNode(Node n1, Node n2){

}

void MatrixEsp::sort(){

    for(size_t i = 0; i < matrixE.size(); i++){
        for(size_t indexR = 0; indexR < matrixE[i].listNode.size(); indexR++){
            int indexMinor = indexR;
            for(size_t next = indexR+1; next < matrixE[i].listNode.size(); next++){
                
                if(matrixE[i].listNode[next].value < matrixE[i].listNode[indexMinor].value){
                    indexMinor = next;
                }
            }
            int auxInd = matrixE[i].listNode[indexR].index;
            int auxVal = matrixE[i].listNode[indexR].value;
            matrixE[i].listNode[indexR].index = matrixE[i].listNode[indexMinor].index;
            matrixE[i].listNode[indexR].value = matrixE[i].listNode[indexMinor].value;
            matrixE[i].listNode[indexMinor].index = auxInd;
            matrixE[i].listNode[indexMinor].value = auxVal;
        }
    }
}

bool MatrixEsp::posExists(int row_, int col_){
    if(matrixE[row_].listNode[col].index == col_ && matrixE[row_].index == row_){
        return true;
    } else {
        return false;
    }
}

