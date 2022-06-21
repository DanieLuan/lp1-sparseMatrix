#ifndef MATRIX_ESP_H_
#define MATRIX_ESP_H_

#include <vector>
#include <string>

class Node{
    public:
        int value;
        int index;

        Node(int val, int idx);
};

class List{
    public:
        std::vector<Node> listNode;
        int index;

        List();
        void insertRow(Node temp);
};

class MatrixEsp{
    public:
        std::vector<List> matrixE;
        int col;
        int row;

        MatrixEsp(int row_, int col_);

        
        void insert(int val, int row_, int col_); //insere um novo elemento na posição indicada. caso já exista, subistitui.
        void remove(int row_, int col_); //remove um elemento da matriz
        int get(int row_, int col_); //retorna o elemento da matriz na posição indicada
        bool search(int val, int &row_, int &col_); //procura um valor específico na matriz, caso seja encontrado, retorna por REF a posição
        
        void saveMatrix(std::string dir);
        void loadMatrix(std::string dir);
        
        void print(); //imprime a matriz
        void sort(); //unused
};

#endif