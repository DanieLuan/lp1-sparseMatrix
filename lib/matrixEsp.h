#ifndef STRING_H_
#define STRING_H_

#include <vector>

class Node{
public:
    int value;
    int index;

    Node(int val, int idx);
    int getIndex();
};

class List{
public:
    std::vector<Node> listNode;
    int length;
    int index;

    List();
    void setIndex(int idx);
    void insertRow(Node temp);

};

class MatrixEsp{
public:
    std::vector<List> matrixE;
    int col;
    int row;

    MatrixEsp(int row_, int col_);

    void print();
    void insert(int val, int row_, int col_);
    void remove(int row_, int col_);
    void get(int row_, int col_);
    bool search(int val, int &row_, int &col_);

    bool posExists(int row_, int col_);
};

#endif