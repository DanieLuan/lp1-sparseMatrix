#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
    if((row_ < 0 || row_ > row-1 || col_ < 0 || col_ > col-1)){ //FALTA FAZER OS ESPAÇOS CERTOS
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
    sort();
}

void MatrixEsp::print(){
    bool zero = true;
    std::cout << std::endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(size_t e = 0; e < matrixE[i].listNode.size(); e++){
                if(matrixE[i].listNode[e].index == j){
                    std::cout << matrixE[i].listNode[e].value << " ";
                    zero = false;
                }
            }
            if(zero == true){
                std::cout << "0 ";
            }
            zero = true;
        }
        std::cout << std::endl;
    }
}

void MatrixEsp::remove(int row_,int col_){
    if((row_ < 0 || row_ > row-1 || col_ < 0 || col_ > col-1)){ //FALTA FAZER OS ESPAÇOS CERTOS
        return;
    }
    for(size_t i = 0; i < matrixE[row_].listNode.size(); i++){
        if(matrixE[row_].listNode[i].index == col_){
            matrixE[row_].listNode.erase(matrixE[row_].listNode.begin()+(i));\
            matrixE[row_].listNode.shrink_to_fit();
        }
    }
    sort();
}

int MatrixEsp::get(int row_, int col_){
    if((row_ < 0 || row_ > row-1 || col_ < 0 || col_ > col-1)){ 
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

void MatrixEsp::saveMatrix(std::string dir){
    std::ofstream matrixFile;
    matrixFile.open(dir);

    if(matrixFile.is_open()){
        std::cout << std::endl;
        matrixFile << row << "x" << col << std::endl;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                for(size_t e = 0; e < matrixE[i].listNode.size(); e++){
                    if(matrixE[i].listNode[e].index == j){
                        matrixFile << i << ";" << j << ";" << matrixE[i].listNode[e].value << std::endl;
                    }
                }
            }
        }
    }
}

void MatrixEsp::loadMatrix(std::string dir){
    std::ifstream matrixFile;
    matrixFile.open(dir);

    if(matrixFile.is_open()){
        matrixE.clear();

        matrixFile >> row;
        matrixFile.ignore();
        matrixFile >> col;
        matrixFile.ignore();
        matrixE.resize(row);

        int tempValue;
        int row_;
        int col_;
        do{
            matrixFile >> row_;
            matrixFile.ignore();
            matrixFile >> col_;
            matrixFile.ignore();
            matrixFile >> tempValue;
            matrixFile.ignore();
            insert(tempValue, row_, col_);
        }while(!matrixFile.eof());
    }
}