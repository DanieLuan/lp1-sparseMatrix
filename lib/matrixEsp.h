#ifndef STRING_H_
#define STRING_H_

class Node{
public:
    int value;
    int index;
    int *next;

    Node();
    ~Node();
};

class List{
public:
    Node* listNode;
    int index;

    List();
    ~List();

};

class MatrixEsp{
public:
    List* matrix;
    int col;
    int row;

    MatrixEsp(int row_, int col_);
    ~MatrixEsp();

    void print();
    void insert(int val, int row_, int col_);
    void remove(int row_, int col_);
    void get(int row_, int col_);
    bool search(int val, int &row_, int &col_);
};

#endif