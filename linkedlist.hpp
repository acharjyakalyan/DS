#ifndef LINKEDLIST
#define LINKEDLIST

#include<iostream>
#include<cstdlib>
#define CUR_TYPE int
using namespace std;

class Node {
public:
    CUR_TYPE data;
    Node* next;
};

class linkedlist {
private:
    Node* Head;
    Node* Tail;
    int size;

public:
    int sizes() const;
    linkedlist();
    linkedlist(int data);
    ~linkedlist();

    int insert_beg(int data);
    int insert_end(int data);
    int del_end();
    int del_beg();
    int show();
    int is_empty();
    linkedlist operator+(const linkedlist &other) const;
};

#endif
